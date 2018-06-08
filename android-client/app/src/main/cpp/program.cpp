//
// Created by viewsharp on 12.04.18.
//

#include "program.h"
#include "assert.h"

static GLuint compile_shader(const GLenum type, const GLchar *source, const GLint length);

static GLuint link_program(const GLuint vertex_shader, const GLuint fragment_shader);

static GLuint build_program(
        const GLchar *vertex_shader_source, const GLint vertex_shader_source_length,
        const GLchar *fragment_shader_source, const GLint fragment_shader_source_length);

// -------------------------------------- Shaders data ---------------------------------------------

static const char shaders_texture_vertex[] = ""
        "uniform vec4 u_Position;\n"
        "attribute vec4 a_Position;\n"
        "attribute vec2 a_TextureCoordinates;\n"
        "\n"
        "varying vec2 v_TextureCoordinates;\n"
        "\n"
        "void main()\n"
        "{\n"
        "    v_TextureCoordinates = a_TextureCoordinates;\n"
        "    gl_Position = a_Position + u_Position;\n"
        "}";

static const char shaders_texture_fragment[] = ""
        "precision mediump float;\n"
        "\n"
        "uniform sampler2D u_TextureUnit;\n"
        "varying vec2 v_TextureCoordinates;\n"
        "\n"
        "void main()\n"
        "{\n"
        "    gl_FragColor = texture2D(u_TextureUnit, v_TextureCoordinates);\n"
        "}";

static const char shaders_color_vertex[] = ""
        "attribute vec4 a_Position;\n"
        "void main()\n"
        "{\n"
        "    gl_Position = a_Position;\n"
        "}";

static const char shaders_color_fragment[] = ""
        "precision mediump float;\n"
        "uniform vec4 u_Color;\n"
        "void main()\n"
        "{\n"
        "    gl_FragColor = u_Color;\n"
        "}";

// -------------------------------------------------------------------------------------------------

TextureProgram get_texture_program() {
    const GLuint program = build_program(
            shaders_texture_vertex, sizeof(shaders_texture_vertex) / sizeof(char),
            shaders_texture_fragment, sizeof(shaders_texture_fragment) / sizeof(char)
    );

    return (TextureProgram) {
            program,
            glGetAttribLocation(program, "a_Position"),
            glGetAttribLocation(program, "a_TextureCoordinates"),
            glGetUniformLocation(program, "u_Position"),
            glGetUniformLocation(program, "u_TextureUnit")
    };
}

ColorProgram get_color_program() {
    const GLuint program = build_program(
            shaders_color_vertex, sizeof(shaders_color_vertex) / sizeof(char),
            shaders_color_fragment, sizeof(shaders_color_fragment) / sizeof(char)
    );

    return (ColorProgram) {
            program,
            glGetAttribLocation(program, "a_Position"),
            glGetUniformLocation(program, "u_Color")
    };
}

static GLuint compile_shader(const GLenum type, const GLchar *source, const GLint length) {
    assert(source != NULL);

    // We create a new shader object
    GLuint shader_object_id = glCreateShader(type);
    GLint compile_status;

    assert(shader_object_id != 0);

    // Pass in the source, compile shader
    glShaderSource(shader_object_id, 1, (const GLchar **) &source, &length);
    glCompileShader(shader_object_id);
    glGetShaderiv(shader_object_id, GL_COMPILE_STATUS, &compile_status);

    assert(compile_status != 0);

    // If everything was successful, we then return the shader ID
    return shader_object_id;
}

static GLuint link_program(const GLuint vertex_shader, const GLuint fragment_shader) {
    // Creat a program
    GLuint program_object_id = glCreateProgram();
    GLint link_status;

    assert(program_object_id != 0);

    // ling shaders with program
    glAttachShader(program_object_id, vertex_shader);
    glAttachShader(program_object_id, fragment_shader);
    glLinkProgram(program_object_id);
    glGetProgramiv(program_object_id, GL_LINK_STATUS, &link_status);

    assert(link_status != 0);

    // If all was successful, then we return the program object ID
    return program_object_id;
}

static GLuint build_program(
        const GLchar *vertex_shader_source, const GLint vertex_shader_source_length,
        const GLchar *fragment_shader_source, const GLint fragment_shader_source_length) {
    assert(vertex_shader_source != NULL);
    assert(fragment_shader_source != NULL);

    GLuint vertex_shader = compile_shader(
            GL_VERTEX_SHADER, vertex_shader_source, vertex_shader_source_length);
    GLuint fragment_shader = compile_shader(
            GL_FRAGMENT_SHADER, fragment_shader_source, fragment_shader_source_length);
    return link_program(vertex_shader, fragment_shader);
}