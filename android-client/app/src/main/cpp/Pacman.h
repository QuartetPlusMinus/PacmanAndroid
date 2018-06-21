//
// Created by views on 20.06.18.
//

#ifndef ANDROID_CLIENT_PACMAN_H
#define ANDROID_CLIENT_PACMAN_H

#include <Serialization/Samples.h>
#include "Unit.h"

static float pacmanZIndex = 0.1f;

class Pacman : public Unit {
public:
    Pacman(const Samples::UnitInit &unit, bool main = false);

    void draw() final;

    void init() final;

    void setTexture(std::shared_ptr<od::Texture> texture) final;

private:
    od::Sprite healthSprite;
    float xTexturePosition;
    int dyingPoint;
};

#endif //ANDROID_CLIENT_PACMAN_H
