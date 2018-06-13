//
// Created by views on 08.06.18.
//

#ifndef ANDROID_CLIENT_UNIT_H
#define ANDROID_CLIENT_UNIT_H

#include <Messages.h>
#include "IDrawable.h"

class Unit : public Messages::UnitInit, public IDrawable {
public:
    Unit() = default;
    Unit(Messages::UnitInit &unitInit) : Messages::UnitInit(unitInit) {};
};

class Pacman : public Unit {
public:
    Pacman(Messages::UnitInit &unit) : Unit(unit), sprite() {
        sprite.setTexturePosition(0.7142f, 0);
    }

    void init() final {
        sprite.init();
    }

    void draw() final {
        sprite.draw();
    }

    void setTexture(OpenDraw::Texture &texture) final {
        sprite.setTexture(texture);
    }

private:
    OpenDraw::Sprite sprite;
};

class Ghost : public Unit {


};

#endif //ANDROID_CLIENT_UNIT_H
