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
const float UNIT_TEXTURE_STEP = 2 * HTS;

static const float UNIT_Z_INDEX_STEP = 0.001f;
static const float INITIAL_PACMAN_Z_INDEX = 0.1f;
static const float INITIAL_GHOST_Z_INDEX = 0.2f;

static const float UNIT_GO_RIGHT_TEXTURE_POSITIONS_Y = 0.0f;
static const float UNIT_GO_DOWN_TEXTURE_POSITIONS_Y = VTS;
static const float UNIT_GO_LEFT_TEXTURE_POSITIONS_Y = 2 * VTS;
static const float UNIT_GO_UP_TEXTURE_POSITIONS_Y = 3 * VTS;

class Unit : public Samples::UnitInit, public IDrawable {
public:
    Unit() = default;

    Unit(const Samples::UnitInit &unitInit) : Samples::UnitInit(unitInit) , speed(SPEED) {};

    void init() override;

    virtual void setTexture(std::shared_ptr<od::Texture> texture);

    float speed;

protected:
    od::Sprite sprite;

    void getPosition(float &x, float &y);

    float getYTexturePosition() {
        switch (data().direction()) {
            case Samples::RIGHT:
                return UNIT_GO_RIGHT_TEXTURE_POSITIONS_Y;
            case Samples::DOWN:
                return UNIT_GO_DOWN_TEXTURE_POSITIONS_Y;
            case Samples::LEFT:
                return UNIT_GO_LEFT_TEXTURE_POSITIONS_Y;
            case Samples::UP:
                return UNIT_GO_UP_TEXTURE_POSITIONS_Y;
            default:
                return 0.0f;
        }
    }
};

#endif //ANDROID_CLIENT_UNIT_H
