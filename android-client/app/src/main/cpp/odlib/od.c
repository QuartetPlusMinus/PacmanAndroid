//
// Created by viewsharp on 11.04.18.
//
#include "od.h"

void drawer_init() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
}


void drawer_set_view_port(int x, int y, int width, int height) {
    glViewport(x, y, width, height);
}