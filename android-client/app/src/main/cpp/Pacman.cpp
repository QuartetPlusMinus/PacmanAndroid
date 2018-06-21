//
// Created by views on 20.06.18.
//

#include <Constants/ConstValues.h>
#include "Pacman.h"

void Pacman::init() {
    sprite.init();
    healthSprite.init();
}

Pacman::Pacman(const Samples::UnitInit &unit, bool main) : Unit(unit) {
    if (main) {
        xTexturePosition = 12 * HTS;
    } else {
        xTexturePosition = 10 * HTS;
    }

    pacmanZIndex += 0.001;
    sprite.setZIndex(pacmanZIndex);
    sprite.setTextureSize(VTS, HTS);
    sprite.setTexturePosition(xTexturePosition, 0);
    sprite.setSize(1.0f / GameMap::HEIGHT, 1.0f / GameMap::WIDTH);
    sprite.setPosition((float) data().pos().x() / GameMap::WIDTH,
                       (float) data().pos().y() / GameMap::HEIGHT);

    healthSprite.setZIndex(pacmanZIndex);
    healthSprite.setTextureSize(0.5f * VTS, 1.5f * HTS);
    healthSprite.setTexturePosition(14 * HTS, 0.0f);
    healthSprite.setSize(0.5f / GameMap::HEIGHT, 1.5f / GameMap::WIDTH);
    healthSprite.setPosition((float) data().pos().x() / GameMap::WIDTH,
                             (float) data().pos().y() / GameMap::HEIGHT);

}

void Pacman::draw() {
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
            default:
                break;
        }
        if (data().entrypercent() == 0.0f) {
            sprite.setTexturePosition(xTexturePosition, yTexturePosition);
        } else {
            sprite.setTexturePosition(xTexturePosition + HTS, yTexturePosition);
        }
    }

    mutable_data()->set_entrypercent(data().entrypercent() + SPEED);

    float xPos, yPos;
    getPosition(xPos, yPos);

    healthSprite.setTexturePosition(14 * HTS, VTS * 0.5f * (3 - data().health()));
    healthSprite.setPosition(xPos, yPos - 0.02f);
    healthSprite.draw();

    if (data().status() == Samples::DYING and dyingPoint++ % 30 > 15) {
        return;
    }
    sprite.setPosition(xPos, yPos);
    sprite.draw();
}

void Pacman::setTexture(std::shared_ptr<od::Texture> texture) {
    sprite.setTexture(texture);
    healthSprite.setTexture(texture);
}