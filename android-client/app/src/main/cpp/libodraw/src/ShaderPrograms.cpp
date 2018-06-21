//
// Created by views on 08.06.18.
//

#include "ShaderPrograms.h"

using namespace OpenDraw::ShaderPrograms;

// -------------------------------------------------------------------

// ShaderProgram

void ShaderProgram::build(const GLchar *vertex_shader_source,
                          const GLint vertex_shader_source_length,
                          const GLchar *fragment_shader_source,
                          const GLint fragment_shader_source_length) {
    assert(vertex_shader_source != NULL);
    assert(fragment_shader_source != NULL);

    GLuint vertex_shader = Shaders::compile(
            GL_VERTEX_SHADER,
            vertex_shader_source,
            vertex_shader_source_length);
    GLuint fragment_shader = Shaders::compile(
            GL_FRAGMENT_SHADER,
            fragment_shader_source,
            fragment_shader_source_length);
    link(vertex_shader, fragment_shader);
}

void ShaderProgram::link(const GLuint &vertex_shader, const GLuint &fragment_shader) {
    // Creat a id
    id = glCreateProgram();
    GLint link_status;

    assert(id != 0);

    // ling shaders with id
    glAttachShader(id, vertex_shader);
    glAttachShader(id, fragment_shader);
    glLinkProgram(id);
    glGetProgramiv(id, GL_LINK_STATUS, &link_status);

    assert(link_status != 0);
}

GLuint ShaderProgram::getProgram() {
    return id;
}

// -------------------------------------------------------------------

// TextureProgram


void TextureProgram::init() {
    build(
            Shaders::TEXTURE_VERTEX_SHADER,
            sizeof(Shaders::TEXTURE_VERTEX_SHADER) / sizeof(char),
            Shaders::TEXTURE_FRAGMENT_SHADER,
            sizeof(Shaders::TEXTURE_FRAGMENT_SHADER) / sizeof(char)
    );
    aPosition = glGetAttribLocation(id, "a_Position");
    aTextureCoordinates = glGetAttribLocation(id, "a_TextureCoordinates");
    uVertexShift = glGetUniformLocation(id, "u_VertexShift");
    uTextureShift = glGetUniformLocation(id, "u_TextureShift");
    uTextureUnit = glGetUniformLocation(id, "u_TextureUnit");
    uZIndex = glGetUniformLocation(id, "u_ZIndex");
}

GLint TextureProgram::getAPosition() {
    return aPosition;
}

GLint TextureProgram::getATextureCoordinates() {
    return aTextureCoordinates;
}


GLint TextureProgram::getUVertexShift() {
    return uVertexShift;
}

GLint TextureProgram::getUTextureShift() {
    return uTextureShift;
}

GLint TextureProgram::getUTextureUnit() {
    return uTextureUnit;
}

GLint TextureProgram::getUZIndex() {
    return uZIndex;
}