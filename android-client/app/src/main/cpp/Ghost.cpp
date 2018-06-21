//
// Created by views on 20.06.18.
//

#include <random>
#include <Constants/ConstValues.h>
#include "Ghost.h"

Ghost::Ghost(const Samples::UnitInit &unit) : Unit(unit) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, sizeof(GHOST_TEXTURE_POSITIONS_X)/ sizeof(float));
    xTexturePosition = GHOST_TEXTURE_POSITIONS_X[dis(gen)];

    ghostZIndex += UNIT_Z_INDEX_STEP;
    sprite.setZIndex(ghostZIndex);

    sprite.setTexturePosition(xTexturePosition, 0);
    sprite.setSize(1.0f / GameMap::HEIGHT, 1.0f / GameMap::WIDTH);
    sprite.setTextureSize(VTS, HTS);
    sprite.setPosition(static_cast<float> (data().pos().x()) / GameMap::WIDTH,
                       static_cast<float> (data().pos().y()) / GameMap::HEIGHT);
}

void Ghost::draw() {
    if (data().entrypercent() == 0.0f || data().entrypercent() == 0.5f) {
        if (data().entrypercent() == 0.0f) {
            sprite.setTexturePosition(xTexturePosition, getYTexturePosition());
        } else {
            sprite.setTexturePosition(xTexturePosition + HTS, getYTexturePosition());
        }
    }

    mutable_data()->set_entrypercent(data().entrypercent() + speed);

    float xPos, yPos;
    getPosition(xPos, yPos);

    sprite.setPosition(xPos, yPos);
    sprite.draw();
}