//
// Created by views on 08.06.18.
//

#ifndef ANDROID_CLIENT_BACKGROUND_H
#define ANDROID_CLIENT_BACKGROUND_H

#include <GLES2/gl2.h>
#include "buffer.h"
#include "IDrawable.h"
#include "linmath.h"

static const float bgData[] = { 0.0f,  0.0f, 0.5f, 0.5f,
                                    -0.5f, -0.5f, 0.0f, 1.0f,
                                    0.5f, -0.5f, 1.0f, 1.0f,
                                    0.5f,  0.5f, 1.0f, 0.0f,
                                    -0.5f,  0.5f, 0.0f, 0.0f,
                                    -0.5f, -0.5f, 0.0f, 1.0f};

class Background : public IDrawable {
public:
    explicit Background(GLuint texture) {
        this->texture = texture;
        buffer = create_vbo(sizeof(bgData), bgData, GL_STATIC_DRAW);
    }

    void draw() final {
        glUseProgram(texture_program->program);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, table->texture);

        vec4 position = {0.0f, 0.0f, 0.0f, -0.5f};

        glUniform4fv(texture_program->u_position_location, 1, position);

        glUniform1i(texture_program->u_texture_unit_location, 0);

        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glVertexAttribPointer(texture_program->a_position_location, 2, GL_FLOAT,
                              GL_FALSE, 4 * sizeof(GL_FLOAT), BUFFER_OFFSET(0));
        glVertexAttribPointer(texture_program->a_texture_coordinates_location, 2, GL_FLOAT,
                              GL_FALSE, 4 * sizeof(GL_FLOAT), BUFFER_OFFSET(2 * sizeof(GL_FLOAT)));
        glEnableVertexAttribArray(texture_program->a_position_location);
        glEnableVertexAttribArray(texture_program->a_texture_coordinates_location);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 6);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

private:
    GLuint texture;
    GLuint buffer;
};

#endif //ANDROID_CLIENT_BACKGROUND_H
