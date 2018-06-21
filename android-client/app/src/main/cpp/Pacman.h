//
// Created by views on 20.06.18.
//

#ifndef ANDROID_CLIENT_PACMAN_H
#define ANDROID_CLIENT_PACMAN_H

#include <Serialization/Samples.h>
#include <Constants/ConstValues.h>
#include "Unit.h"

static const float PACMAN_TEXTURE_POSITIONS_X = 10 * HTS;
static const float PACMAN_OPEN_MOUTH_TEXTURE_POSITIONS_X = 11 * HTS;
static const float MAIN_PACMAN_TEXTURE_POSITIONS_X = 12 * HTS;
static const float MAIN_PACMAN_OPEN_MOUTH_TEXTURE_POSITIONS_X = 13 * HTS;

static const float HEALTH_TEXTURE_Y_STEP = 0.5f * VTS;
static const float HEALTH_TEXTURE_POSITIONS_X = 14 * HTS;
static const float HEALTH_TEXTURE_POSITIONS_Y[] = {
        HEALTH_TEXTURE_Y_STEP * 3,
        HEALTH_TEXTURE_Y_STEP * 2,
        HEALTH_TEXTURE_Y_STEP,
        0,
};

static const float HEALTH_TEXTURE_HEIGHT = 0.5f * VTS;
static const float HEALTH_TEXTURE_WIDTH = 1.5f * HTS;

static const float HEALTH_HEIGHT = 0.5f / GameMap::HEIGHT;
static const float HEALTH_WIDTH = 1.5f / GameMap::WIDTH;
static const float HEALTH_OFFSET_Y = -0.02f;

static float pacmanZIndex = INITIAL_PACMAN_Z_INDEX;

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
    int drowPoint;

    bool doDraw() {
        return (data().status() != Samples::DYING || dyingPoint++ % 30 > 15);
    }

    bool howDraw() {
        return drowPoint++ % 30 > 15;
    }

};

#endif //ANDROID_CLIENT_PACMAN_H
