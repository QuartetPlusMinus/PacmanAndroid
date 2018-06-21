//
// Created by views on 20.06.18.
//

#include <Constants/ConstValues.h>
#include "Pacman.h"

void Pacman::init() {
    sprite.init();
    healthSprite.init();
}

Pacman::Pacman(const Samples::UnitInit &unit, bool main) : Unit(unit), dyingPoint(0), drowPoint(0) {
    if (main) {
        xTexturePosition = MAIN_PACMAN_TEXTURE_POSITIONS_X;
    } else {
        xTexturePosition = PACMAN_TEXTURE_POSITIONS_X;
    }

    pacmanZIndex += UNIT_Z_INDEX_STEP;
    sprite.setZIndex(pacmanZIndex);

    sprite.setTextureSize(VTS, HTS);
    sprite.setTexturePosition(xTexturePosition, 0);
    sprite.setSize(1.0f / GameMap::HEIGHT, 1.0f / GameMap::WIDTH);
    sprite.setPosition(static_cast<float>(data().pos().x()) / GameMap::WIDTH,
                       static_cast<float>(data().pos().y()) / GameMap::HEIGHT);

    healthSprite.setZIndex(pacmanZIndex);
    healthSprite.setTextureSize(HEALTH_TEXTURE_HEIGHT, HEALTH_TEXTURE_WIDTH);
    healthSprite.setTexturePosition(HEALTH_TEXTURE_POSITIONS_X, 0.0f);
    healthSprite.setSize(HEALTH_HEIGHT, HEALTH_WIDTH);
    healthSprite.setPosition(static_cast<float>(data().pos().x()) / GameMap::WIDTH,
                             static_cast<float>(data().pos().y()) / GameMap::HEIGHT);

}

void Pacman::draw() {
//    if (data().entrypercent() == 0.0f || data().entrypercent() == 0.5f) {
        if (howDraw()) {
            sprite.setTexturePosition(xTexturePosition, getYTexturePosition());
        } else {
            sprite.setTexturePosition(xTexturePosition + HTS, getYTexturePosition());
        }
//    }

    mutable_data()->set_entrypercent(data().entrypercent() + speed);

    float xPos, yPos;
    getPosition(xPos, yPos);

    healthSprite.setTexturePosition(HEALTH_TEXTURE_POSITIONS_X, HEALTH_TEXTURE_POSITIONS_Y[data().health()]);
    healthSprite.setPosition(xPos, yPos + HEALTH_OFFSET_Y);
    healthSprite.draw();

    if (doDraw()) {
        sprite.setPosition(xPos, yPos);
        sprite.draw();
    }
}

void Pacman::setTexture(std::shared_ptr<od::Texture> texture) {
    sprite.setTexture(texture);
    healthSprite.setTexture(texture);
}