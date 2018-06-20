//
// Created by murmurt on 20.06.18.
//

#ifndef SERVER_GAMEOBJECT_H
#define SERVER_GAMEOBJECT_H

#include <Serialization/Samples.h>
#include <cmath>


class RoundPosition {
public:
    RoundPosition() : x(0), y(0) {
    };

    friend const bool operator==(const RoundPosition &position1, const RoundPosition &position2);

    void setPosition(unsigned int x_, unsigned int y_, Samples::Direction direction, float entryPercent) {
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

private:
    unsigned int x;
    unsigned int y;

};

const bool operator==(const RoundPosition &position1, const RoundPosition &position2) {
    if ((position1.x == position2.x) && (position1.y == position2.y)) {
        return true;
    }
    return false;
}


#endif //SERVER_GAMEOBJECT_H
