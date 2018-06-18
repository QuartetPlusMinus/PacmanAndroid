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

    void init() final {
        sprite.init();
    }

    void draw() final {
        step();
        switch (data().direction()) {
            case Messages::RIGHT :
                sprite.setPosition(data().pos().x() / 15.0f + data().entrypercent(),
                                   data().pos().y() / 24.0f
                );
                break;
            default:
                break;
        }
        sprite.draw();
    }

    void setTexture(OpenDraw::Texture &texture) final {
        sprite.setTexture(texture);
    }

    void step() {
        mutable_data()->set_entrypercent(data().entrypercent() + 0.0014f);
    }

protected:
    OpenDraw::Sprite sprite;
};

class Pacman : public Unit {
public:
    Pacman(Messages::UnitInit &unit) : Unit(unit) {
        sprite.setTexturePosition(0.7142f, 0);
        sprite.setSize(0.0416f, 0.0666f);
        sprite.setTextureSize(0.25f, 0.0714f);
        sprite.setZIndex(0.01);
        // TODO: make consts
        sprite.setPosition(data().pos().x() / 15.0f, data().pos().y() / 24.0f);
    }
};

class Ghost : public Unit {
public:
    Ghost(Messages::UnitInit &unit) : Unit(unit) {
        sprite.setTexturePosition(0, 0);
        sprite.setSize(0.0416f, 0.0666f);
        sprite.setTextureSize(0.25f, 0.0714f);
        sprite.setZIndex(0.01);

        // TODO: make consts
        sprite.setPosition(data().pos().x() / 15.0f, data().pos().y() / 24.0f);
    }
};

#endif //ANDROID_CLIENT_UNIT_H
