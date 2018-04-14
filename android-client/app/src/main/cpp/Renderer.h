//
// Created by viewsharp on 11.04.18.
//

#ifndef PACMANANDROID_RENDERER_H
#define PACMANANDROID_RENDERER_H

#include <android/asset_manager_jni.h>

void onSurfaceCreated(AAssetManager* assetManager);

void onSurfaceChanged(unsigned int width, unsigned int height);

void onDrawFrame();

#endif //PACMANANDROID_RENDERER_H
