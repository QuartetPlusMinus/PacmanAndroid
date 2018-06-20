//
// Created by views on 20.06.18.
//

#ifndef ANDROID_CLIENT_GHOST_H
#define ANDROID_CLIENT_GHOST_H

#include "Unit.h"

static float ghostZIndex = 0.2f;

class Ghost : public Unit {
public:
    Ghost(Samples::UnitInit &unit);

    void draw() final;

private:
    float xTexturePosition;
};

#endif //ANDROID_CLIENT_GHOST_H
