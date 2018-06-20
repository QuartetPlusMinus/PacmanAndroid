//
// Created by murmurt on 20.06.18.
//

#include "GameObject.h"

const bool operator==(const RoundPosition &position1, const RoundPosition &position2) {
    if ((position1.x == position2.x) && (position1.y == position2.y)) {
        return true;
    }
    return false;
}