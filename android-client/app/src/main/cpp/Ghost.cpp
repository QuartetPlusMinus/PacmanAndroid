//
// Created by views on 20.06.18.
//

#include <random>
#include <Constants/ConstValues.h>
#include "Ghost.h"

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

void Ghost::draw() {
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

    float xPos, yPos;
    getPosition(xPos, yPos);

    sprite.setPosition(xPos, yPos);
    sprite.draw();
}