//
// Created by viewsharp on 05.04.18.
//

#ifndef PACMANANDROID_TEXTURE_H
#define PACMANANDROID_TEXTURE_H

#include <GLES2/gl2.h>
#include <cassert>

GLuint load_texture(
        const GLsizei width, const GLsizei height,
        const GLenum type, const GLvoid* pixels);

#endif //PACMANANDROID_TEXTURE_H
