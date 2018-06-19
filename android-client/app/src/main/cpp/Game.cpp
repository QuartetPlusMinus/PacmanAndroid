//
// Created by viewsharp on 11.04.18.
//


#include "Game.h"

void Game::onSurfaceCreated() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    od::Texture bgTexture(assetManager, "textures/map.png");
    background.setTexture(std::make_shared<od::Texture>(bgTexture));
    background.init();

    std::shared_ptr<od::Texture> unitTexture = std::make_shared<od::Texture>(
            od::Texture(assetManager, "textures/units.png"));
    for (int i = 0; i < unitsCount; i++) {
        units[i]->init();
        units[i]->setTexture(unitTexture);
    }

    started = true;
}

void Game::onSurfaceChanged(int width, int height) {
    glViewport(0, 0, width, height);
}

void Game::onDrawFrame() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    background.draw();
    for (int i = 0; i < unitsCount; i++) {
        units[i]->draw();
    }
}

void Game::setAssertManager(AAssetManager *assetManager) {
    this->assetManager = assetManager;
}

void Game::start(Messages::StartMessage &startMessage) {
    id = startMessage.id();

    unitsCount = startMessage.unit_size();
    units = new Unit *[unitsCount];

    for (int i = 0; i < unitsCount; i++) {
        // TODO: factory or builder
        auto unit = startMessage.unit(i);
        if (unit.type() == Samples::PACMAN) {
            units[i] = new Pacman(unit);
        } else if (unit.type() == Samples::GHOST) {
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
    started = false;
}

bool Game::isStarted() {
    return started;
}