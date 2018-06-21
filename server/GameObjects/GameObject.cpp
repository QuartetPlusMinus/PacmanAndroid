//
// Created by murmurt on 20.06.18.
//

#include "GameObject.h"



const bool operator==(const RoundPosition &position1, const RoundPosition &position2) {
    return ((position1.x == position2.x) && (position1.y == position2.y));
}

void RoundPosition::setPosition(unsigned int x_, unsigned int y_, Samples::Direction direction, float entryPercent) {
    switch (direction) {
        case Samples::Direction::RIGHT:
            x = round(x_ + entryPercent);
            y = y_;
            break;
        case Samples::Direction::LEFT:
            x = round(x_ - entryPercent);
            y = y_;
        case Samples::Direction::UP:
            x = x_;
            y = round(y_ - entryPercent);
        case Samples::Direction::DOWN:
            x = x_;
            y = round(y_ + entryPercent);
        default:
            break;
    }
}
