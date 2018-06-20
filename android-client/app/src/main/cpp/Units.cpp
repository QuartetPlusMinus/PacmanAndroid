//
// Created by views on 08.06.18.
//

#include <random>
#include <Constants/ConstValues.h>
#include "Units.h"

const float HTS = 0.0714286f; // horizontal texture step
const float VTS = 0.25f; // vertical texture step
const float SPEED = 0.014f;

void Unit::init() {
    sprite.init();
}

void Unit::draw() {
    step();
    switch (data().direction()) {
        case Samples::RIGHT :
            sprite.setPosition((data().pos().x() + data().entrypercent()) / GameMap::WIDTH,
                               (float) data().pos().y() / GameMap::HEIGHT);
            break;
        case Samples::DOWN :
            sprite.setPosition((float) data().pos().x() / GameMap::WIDTH,
                               (data().pos().y() + data().entrypercent()) / GameMap::HEIGHT);
            break;
        case Samples::LEFT :
            sprite.setPosition((data().pos().x() - data().entrypercent()) / GameMap::WIDTH,
                               (float) data().pos().y() / GameMap::HEIGHT);
            break;
        case Samples::UP :
            sprite.setPosition((float) data().pos().x() / GameMap::WIDTH,
                               (data().pos().y() - data().entrypercent()) / GameMap::HEIGHT);
            break;
        default:
            break;
    }
    sprite.draw();
}

void Unit::setTexture(std::shared_ptr<od::Texture> texture) {
    sprite.setTexture(texture);
}

void Unit::step() {
    mutable_data()->set_entrypercent(data().entrypercent() + SPEED);
}


Pacman::Pacman(Samples::UnitInit &unit) : Unit(unit) {
    sprite.setTexturePosition(10 * HTS, 0);
    sprite.setSize(1.0f / GameMap::HEIGHT, 1.0f / GameMap::WIDTH);
    sprite.setTextureSize(VTS, HTS);
    pacmanZIndex += 0.001;
    sprite.setZIndex(pacmanZIndex
    );
    sprite.setPosition((float) data().pos().x() / GameMap::WIDTH,
                       (float) data().pos().y() / GameMap::HEIGHT);
}

void Pacman::step() {
    if (data().entrypercent() == 0.0f || data().entrypercent() == 0.5f) {
        float yTexturePosition = 0.0f;
        switch (data().direction()) {
            case Samples::RIGHT:
                yTexturePosition = 0.0f;
                break;
            case Samples::DOWN:
                yTexturePosition = VTS;
                break;
            case Samples::LEFT:
                yTexturePosition = 2 * VTS;
                break;
            case Samples::UP:
                yTexturePosition = 3 * VTS;
                break;
        }
        if (data().entrypercent() == 0.0f) {
            sprite.setTexturePosition(10 * HTS, yTexturePosition);
        } else {
            sprite.setTexturePosition(11 * HTS, yTexturePosition);
        }
    }

    mutable_data()->set_entrypercent(data().entrypercent() + SPEED);
}

Ghost::Ghost(Samples::UnitInit &unit) : Unit(unit) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, 4);
    xTexturePosition = dis(gen) * 2 * HTS;

    sprite.setTexturePosition(xTexturePosition, 0);
    sprite.setSize(1.0f / GameMap::HEIGHT, 1.0f / GameMap::WIDTH);
    sprite.setTextureSize(VTS, HTS);
    ghostZIndex += 0.001;
    sprite.setZIndex(ghostZIndex);
    sprite.setPosition((float) data().pos().x() / GameMap::WIDTH,
                       (float) data().pos().y() / GameMap::HEIGHT);
}

void Ghost::step() {
    if (data().entrypercent() == 0.0f || data().entrypercent() == 0.5f) {
        float yTexturePosition = 0.0f;
        switch (data().direction()) {
            case Samples::RIGHT:
                yTexturePosition = 0.0f;
                break;
            case Samples::DOWN:
                yTexturePosition = VTS;
                break;
            case Samples::LEFT:
                yTexturePosition = 2 * VTS;
                break;
            case Samples::UP:
                yTexturePosition = 3 * VTS;
                break;
        }
        if (data().entrypercent() == 0.0f) {
            sprite.setTexturePosition(xTexturePosition, yTexturePosition);
        } else {
            sprite.setTexturePosition(xTexturePosition + HTS, yTexturePosition);
        }
    }

    mutable_data()->set_entrypercent(data().entrypercent() + SPEED);
}
