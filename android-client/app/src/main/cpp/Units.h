//
// Created by views on 08.06.18.
//

#ifndef ANDROID_CLIENT_UNIT_H
#define ANDROID_CLIENT_UNIT_H

#include <Serialization/Samples.h>
#include "libodraw/libodraw.h"
#include "IDrawable.h"

class Unit : public Samples::UnitInit, public IDrawable {
public:
    Unit() = default;

    Unit(Samples::UnitInit &unitInit) : Samples::UnitInit(unitInit) {};

    void init() final;

    void draw() final;

    void setTexture(std::shared_ptr<od::Texture> texture);

    virtual void step();

protected:
    od::Sprite sprite;
};


static float pacmanZIndex = 0.1f;

class Pacman : public Unit {
public:
    Pacman(Samples::UnitInit &unit);

    void step() final;
};

static float ghostZIndex = 0.2f;

class Ghost : public Unit {
public:
    Ghost(Samples::UnitInit &unit);

    void step() final;

private:
    float xTexturePosition;
};

#endif //ANDROID_CLIENT_UNIT_H
