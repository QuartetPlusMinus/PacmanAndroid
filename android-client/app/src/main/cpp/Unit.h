//
// Created by views on 20.06.18.
//

#ifndef ANDROID_CLIENT_UNIT_H
#define ANDROID_CLIENT_UNIT_H

#include <Serialization/Samples.h>
#include "IDrawable.h"

const float HTS = 0.0625f; // horizontal texture step
const float VTS = 0.25f; // vertical texture step
const float SPEED = 0.014f;

class Unit : public Samples::UnitInit, public IDrawable {
public:
    Unit() = default;

    Unit(const Samples::UnitInit &unitInit) : Samples::UnitInit(unitInit) {};

    void init() override;

    virtual void setTexture(std::shared_ptr<od::Texture> texture);

protected:
    od::Sprite sprite;

    void getPosition(float &x, float &y);
};

#endif //ANDROID_CLIENT_UNIT_H
