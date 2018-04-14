//
// Created by viewsharp on 11.04.18.
//

#ifndef PACMANANDROID_GAME_H
#define PACMANANDROID_GAME_H

#include <android/asset_manager_jni.h>
#include <unistd.h>
#include "odlib/od.h"

#include "GameObjects/Unit.h"
#include "GameObjects/GameObjectFactory.h"

class Game {
public:
    Game(AAssetManager* assetManager);

    ~Game() {}

    void changeSurface(unsigned int width, unsigned int height);
    void draw();
    void over();

private:
    AAssetManager* manager;

    unsigned int unitCount;
    Unit** units;

    int id;

};

#endif //PACMANANDROID_GAME_H
