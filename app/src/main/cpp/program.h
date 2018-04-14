//
// Created by viewsharp on 12.04.18.
//

#ifndef PACMANANDROID_PROGRAM_H
#define PACMANANDROID_PROGRAM_H

#include <GLES2/gl2.h>

typedef struct {
    GLuint program;

    GLint a_position_location;
    GLint a_texture_coordinates_location;
    GLint u_mvp_matrix_location;
    GLint u_texture_unit_location;
} TextureProgram;

typedef struct {
    GLuint program;

    GLint a_position_location;
    GLint u_mvp_matrix_location;
    GLint u_color_location;
} ColorProgram;

TextureProgram get_texture_program();
ColorProgram get_color_program();

#endif //PACMANANDROID_PROGRAM_H
