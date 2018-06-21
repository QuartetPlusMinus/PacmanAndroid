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

    void setPosition(unsigned int x_, unsigned int y_, Samples::Direction direction, float entryPercent);

private:
    unsigned int x;
    unsigned int y;

};




#endif //SERVER_GAMEOBJECT_H
