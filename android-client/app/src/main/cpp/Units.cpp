//
// Created by views on 08.06.18.
//

#include <Constants/ConstValues.h>
#include "Units.h"

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
    mutable_data()->set_entrypercent(data().entrypercent() + 0.014f);
}


Pacman::Pacman(Samples::UnitInit &unit) : Unit(unit) {
    sprite.setTexturePosition(0.7142f, 0);
    sprite.setSize(0.0416f, 0.0666f);
    sprite.setTextureSize(0.25f, 0.0714f);
    sprite.setZIndex(0.01);
    sprite.setPosition((float) data().pos().x() / GameMap::WIDTH,
                       (float) data().pos().y() / GameMap::HEIGHT);
}

Ghost::Ghost(Samples::UnitInit &unit) : Unit(unit) {
    sprite.setTexturePosition(0, 0);
    sprite.setSize(0.0416f, 0.0666f);
    sprite.setTextureSize(0.25f, 0.0714f);
    sprite.setZIndex(0.01);
    sprite.setPosition((float) data().pos().x() / GameMap::WIDTH,
                       (float) data().pos().y() / GameMap::HEIGHT);
}
