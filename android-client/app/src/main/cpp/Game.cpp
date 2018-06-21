//
// Created by viewsharp on 11.04.18.
//

#include "Game.h"
#include "Pacman.h"
#include "Ghost.h"

const std::string MAP_TEXTURE_PATH = "textures/map.png";
const std::string UNITS_TEXTURE_PATH = "textures/units.png";

void Game::onSurfaceCreated() {
    assert(assetManager != nullptr);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    od::Texture bgTexture(assetManager, MAP_TEXTURE_PATH);
    background.setTexture(std::make_shared<od::Texture>(bgTexture));
    background.init();

    std::shared_ptr<od::Texture> unitTexture = std::make_shared<od::Texture>(
            od::Texture(assetManager, UNITS_TEXTURE_PATH));
    for (auto &unit: units) {
        unit->init();
        unit->setTexture(unitTexture);
    }

    started = true;
}

void Game::onSurfaceChanged(int width, int height) {
    glViewport(0, 0, width, height);
}

void Game::onDrawFrame() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    background.draw();
    for (auto &unit: units) {
        unit->draw();
    }
}

void Game::setAssertManager(AAssetManager *assetManager) {
    this->assetManager = assetManager;
}

void Game::start(Messages::StartMessage &startMessage) {
    id = startMessage.id();

    for (int i = 0; i < startMessage.unit_size(); i++) {
        // TODO: factory or builder
        const Samples::UnitInit &unit = startMessage.unit(i);

        if (unit.type() == Samples::PACMAN) {
            units.emplace_back(new Pacman(unit, i == startMessage.id()));
        } else if (unit.type() == Samples::GHOST) {
            units.emplace_back(new Ghost(unit));
        }
    }
}

void Game::iterate(Messages::IterationMessage &iterationMessage) {
    for (int i = 0; i < iterationMessage.unit_size(); i++) {
        auto &unit = iterationMessage.unit(i);
        if (!units[i]->has_data()) {
            *units[i]->mutable_data() = unit;
        } else if (units[i]->data().status() == unit.status() and
            units[i]->data().direction() == unit.direction() and
            units[i]->data().pos().x() == unit.pos().x() and
            units[i]->data().pos().y() == unit.pos().y() and
            abs(units[i]->data().entrypercent() - unit.entrypercent()) < 0.1f
                ) {
            if (units[i]->data().entrypercent() > unit.entrypercent()) {
                units[i]->speed -=0.001f;
            } else {
                units[i]->speed +=0.001f;
            }
            continue;
        } else {
            *units[i]->mutable_data() = unit;
        }
    }
}

void Game::end(Messages::EndMessage &endMessage) {
    started = false;
}

bool Game::isStarted() {
    return started;
}