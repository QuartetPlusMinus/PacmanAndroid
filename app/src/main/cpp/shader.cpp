//
// Created by viewsharp on 05.04.18.
//

//#include <stdlib.h>
//#include <string.h>

#include "shader.h"
#include <cassert>

GLuint compile_shader(const GLenum type, const GLchar* source, const GLint length) {
    assert(source != NULL);
    GLuint shader_object_id = glCreateShader(type);
    GLint compile_status;

    assert(shader_object_id != 0);

    glShaderSource(shader_object_id, 1, (const GLchar **)&source, &length);
    glCompileShader(shader_object_id);
    glGetShaderiv(shader_object_id, GL_COMPILE_STATUS, &compile_status);

//    if (LOGGING_ON) {
//        DEBUG_LOG_WRITE_D(TAG, "Results of compiling shader source:");
//        log_v_fixed_length(source, length);
//        log_shader_info_log(shader_object_id);
//    }

    assert(compile_status != 0);

    return shader_object_id;
}

GLuint link_program(const GLuint vertex_shader, const GLuint fragment_shader) {
    GLuint program_object_id = glCreateProgram();
    GLint link_status;

    assert(program_object_id != 0);

    glAttachShader(program_object_id, vertex_shader);
    glAttachShader(program_object_id, fragment_shader);
    glLinkProgram(program_object_id);
    glGetProgramiv(program_object_id, GL_LINK_STATUS, &link_status);

//    if (LOGGING_ON) {
//        DEBUG_LOG_WRITE_D(TAG, "Results of linking program:");
//        log_program_info_log(program_object_id);
//    }

    assert(link_status != 0);

    return program_object_id;
}

GLuint build_program(
        const GLchar * vertex_shader_source, const GLint vertex_shader_source_length,
        const GLchar * fragment_shader_source, const GLint fragment_shader_source_length) {
    assert(vertex_shader_source != NULL);
    assert(fragment_shader_source != NULL);

    GLuint vertex_shader = compile_shader(
            GL_VERTEX_SHADER, vertex_shader_source, vertex_shader_source_length);
    GLuint fragment_shader = compile_shader(
            GL_FRAGMENT_SHADER, fragment_shader_source, fragment_shader_source_length);
    return link_program(vertex_shader, fragment_shader);
}