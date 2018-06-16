//
// Created by viewsharp on 11.04.18.
//

#include <Messages.h>

#include "Game.h"


void Game::onSurfaceCreated() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    OpenDraw::Texture textureBG;
    textureBG.loadFromPngAsset("textures/map.png");
    background.setTexture(textureBG);
    background.init();

    OpenDraw::Texture texturePM;
    texturePM.loadFromPngAsset("textures/units.png");
    for (int i = 0; i < unitsCount; i++) {
        units[i]->init();
        units[i]->setTexture(texturePM);
    }
}

void Game::onSurfaceChanged(int width, int height) {
    glViewport(0, 0, width, height);
}

void Game::onDrawFrame() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (int i = 0; i < unitsCount; i++) {
        units[i]->draw();
    }
    background.draw();
}

void Game::init() {

}

void Game::start(Messages::StartMessage &startMessage) {
    id = startMessage.id();

    unitsCount = startMessage.unit_size();
    units = new Unit *[unitsCount];

    for (int i = 0; i < unitsCount; i++) {
        // TODO: factory or builder
        auto unit = startMessage.unit(i);
        if (unit.type() == Messages::PACMAN) {
            units[i] = new Pacman(unit);
        } else if (unit.type() == Messages::GHOST) {
            units[i] = new Ghost(unit);
        }
    }
}

void Game::iterate(Messages::IterationMessage &iterationMessage) {
    for (int i = 0; i < unitsCount; i++) {
        *units[i]->mutable_data() = iterationMessage.unit(i);
    }
}

void Game::end(Messages::EndMessage &endMessage) {

}