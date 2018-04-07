//
// Created by viewsharp on 05.04.18.
//

#include "buffer.h"

GLuint createVBO(const GLsizeiptr size, const GLvoid* data, const GLenum usage) {
    assert(data != NULL);
    GLuint vbo_object;
    glGenBuffers(1, &vbo_object);
    assert(vbo_object != 0);

    glBindBuffer(GL_ARRAY_BUFFER, vbo_object);
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    return vbo_object;
}