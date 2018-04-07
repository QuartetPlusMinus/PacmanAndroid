//
// Created by viewsharp on 05.04.18.
//

#ifndef PACMANANDROID_BUFFER_H
#define PACMANANDROID_BUFFER_H

#include <GLES2/gl2.h>
#include <cassert>

GLuint createVBO(const GLsizeiptr size, const GLvoid* data, const GLenum usage);

#endif //PACMANANDROID_BUFFER_H
