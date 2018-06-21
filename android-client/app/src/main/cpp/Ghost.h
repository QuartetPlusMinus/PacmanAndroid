//
// Created by views on 20.06.18.
//

#ifndef ANDROID_CLIENT_GHOST_H
#define ANDROID_CLIENT_GHOST_H

#include "Unit.h"

static const float GHOST_TEXTURE_POSITIONS_X[] = {
        0,
        UNIT_TEXTURE_STEP,
        UNIT_TEXTURE_STEP * 2,
        UNIT_TEXTURE_STEP * 3,
        UNIT_TEXTURE_STEP * 4,
};

static float ghostZIndex = INITIAL_GHOST_Z_INDEX;

class Ghost : public Unit {
public:
    explicit Ghost(const Samples::UnitInit &unit);

    void draw() final;

private:
    float xTexturePosition;
};

#endif //ANDROID_CLIENT_GHOST_H
