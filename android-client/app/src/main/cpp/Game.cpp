//
// Created by viewsharp on 11.04.18.
//


#include "Game.h"
#include "game_objects.h"
#include "asset_utils.h"

void Game::onSurfaceCreated() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);

    background = Background(load_png_asset_into_texture("textures/map.png"));

    texture_program = get_texture_program();
    color_program = get_color_program();
}

void Game::onSurfaceChanged(int width, int height) {
    glViewport(0, 0, width, height);
}

void Game::onDrawFrame() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw_table(&table, &texture_program);
}

void Game::start(char *message, size_t size) {

}

void Game::iterate(char *message, size_t size) {

}

void Game::end(char *message, size_t size) {

}