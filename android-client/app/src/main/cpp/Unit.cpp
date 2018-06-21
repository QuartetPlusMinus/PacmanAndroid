//
// Created by views on 20.06.18.
//

#include <Constants/ConstValues.h>
#include "Unit.h"

void Unit::init() {
    sprite.init();
}

void Unit::getPosition(float &x, float &y) {
    switch (data().direction()) {
        case Samples::RIGHT :
            x = (data().pos().x() + data().entrypercent()) / GameMap::WIDTH;
            y = (float) data().pos().y() / GameMap::HEIGHT;
            break;
        case Samples::DOWN :
            x = (float) data().pos().x() / GameMap::WIDTH;
            y = (data().pos().y() + data().entrypercent()) / GameMap::HEIGHT;
            break;
        case Samples::LEFT :
            x = (data().pos().x() - data().entrypercent()) / GameMap::WIDTH;
            y = (float) data().pos().y() / GameMap::HEIGHT;
            break;
        case Samples::UP :
            x = (float) data().pos().x() / GameMap::WIDTH;
            y = (data().pos().y() - data().entrypercent()) / GameMap::HEIGHT;
            break;
        default:
            x = (float) data().pos().x() / GameMap::WIDTH;
            y = (float) data().pos().y() / GameMap::HEIGHT;
    }
}

void Unit::setTexture(std::shared_ptr<od::Texture> texture) {
    sprite.setTexture(texture);
}