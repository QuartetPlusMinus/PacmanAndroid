//
// Created by views on 08.06.18.
//

#include <cassert>
#include "Sprite.h"
#include "linmath.h"

using namespace OpenDraw;

Sprite::Sprite() : buffer(0) {
    setPosition(0.0f, 0.0f);
    setTexturePosition(0.0f, 0.0f);
    setSize(1.0f, 1.0f);
    setTextureSize(1.0f, 1.0f);
    zIndex = 0.0f;
}

void Sprite::setSize(float height, float width) {
    assert(buffer == 0);
    size[0] = width;
    size[1] = height;
}

void Sprite::setTextureSize(float height, float width) {
    assert(buffer == 0);
    tSize[0] = width;
    tSize[1] = height;
}

void Sprite::setTexture(std::shared_ptr<Texture> texture) {
    this->texture = texture;
}

void Sprite::init() {
    const float data[] = {
            -0.5f, 0.5f - size[1], 0.0f, tSize[1],
            -0.5f + size[0], 0.5f - size[1], tSize[0], tSize[1],
            -0.5f, 0.5f, 0.0f, 0.0f,
            -0.5f + size[0], 0.5f, tSize[0], 0.0f,
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

    glActiveTexture(GL_TEXTURE0 + texture->id());
    glBindTexture(GL_TEXTURE_2D, texture->id());

    glUniform2fv(program.getUVertexShift(), 1, position);
    glUniform2fv(program.getUTextureShift(), 1, texturePosition);
    glUniform1i(program.getUTextureUnit(), texture->id());
    glUniform1f(program.getUZIndex(), zIndex);

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

void Sprite::setZIndex(float index) {
    zIndex = index;
}


void Sprite::setPosition(float x, float y) {
    position[0] = x;
    position[1] = -y;
}

void Sprite::setTexturePosition(float x, float y) {
    texturePosition[0] = x;
    texturePosition[1] = y;
}