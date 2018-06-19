//
// Created by views on 08.06.18.
//

#include <cassert>
#include "Shaders.h"

using namespace OpenDraw;

GLuint Shaders::compile(const GLenum type, const GLchar *source, const GLint length) {
    assert(source != NULL);

    // We create a new shader object
    GLuint shader_object_id = glCreateShader(type);
    GLint compile_status;

    assert(shader_object_id != 0);

    // Pass in the source, compile shader
    glShaderSource(shader_object_id, 1, &source, &length);
    glCompileShader(shader_object_id);
    glGetShaderiv(shader_object_id, GL_COMPILE_STATUS, &compile_status);

    assert(compile_status != 0);

    // If everything was successful, we then return the shader ID
    return shader_object_id;
}
