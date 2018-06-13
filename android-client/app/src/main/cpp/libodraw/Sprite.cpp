//
// Created by views on 08.06.18.
//

#include <cassert>
#include "Sprite.h"
#include "linmath.h"

using namespace OpenDraw;


Sprite::Sprite() {
    setPosition(0.0f, 0.0f);
    setSize(1.0f, 1.0f);
    setTexturePosition(0.0f, 0.0f);
    setTextureSize(1.0f, 1.0f);
}

void Sprite::init() {
    const float data[] = {
            -1.0f, -1.0f, 0.0f, 1.0f,
            1.0f, -1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f, 0.0f, 0.0f,
            1.0f, 1.0f, 1.0f, 0.0f,
    };

    // generate new OpenGL vertex buffer object (buffer)
    glGenBuffers(1, &buffer);
    assert(buffer != 0);

    // bind to buffer and upload the data from 'data' into the VBO
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    program.init();
}

void Sprite::draw() {
    glUseProgram(program.getProgram());

    glActiveTexture(GL_TEXTURE0 + texture.getId());
    glBindTexture(GL_TEXTURE_2D, texture.getId());

    glUniform2fv(program.getUVertexShift(), 1, position);
    glUniform2fv(program.getUTextureShift(), 1, texturePosition);
    glUniform1i(program.getUTextureUnit(), texture.getId());

    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    glVertexAttribPointer(program.getAPosition(), 2, GL_FLOAT,
                          GL_TRUE, 4 * sizeof(GL_FLOAT), BUFFER_OFFSET(0));
    glVertexAttribPointer(program.getATextureCoordinates(), 2, GL_FLOAT,
                          GL_TRUE, 4 * sizeof(GL_FLOAT), BUFFER_OFFSET(2 * sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(program.getAPosition());
    glEnableVertexAttribArray(program.getATextureCoordinates());

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glDisableVertexAttribArray(program.getATextureCoordinates());
    glDisableVertexAttribArray(program.getAPosition());

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::setTexture(Texture &texture) {
    this->texture = texture;
}

void Sprite::setPosition(float x, float y) {
    position[0] = x;
    position[1] = -y;
}

void Sprite::setSize(float width, float height) {
    size[0] = width;
    size[1] = height;
}

void Sprite::setTexturePosition(float x, float y) {
    texturePosition[0] = x;
    texturePosition[1] = y;
}

void Sprite::setTextureSize(float width, float height) {
    textureSize[0] = width;
    textureSize[1] = height;
}