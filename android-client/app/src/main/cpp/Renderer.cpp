//
// Created by viewsharp on 11.04.18.
//

#include "Renderer.h"
#include "Game.h"

static Game *game;

void onSurfaceCreated(AAssetManager* assetManager) {
    game = new Game(assetManager);
}

void onSurfaceChanged(unsigned int width, unsigned int height) {
    game->changeSurface(width, height);
}

void onDrawFrame() {
    game->draw();
}