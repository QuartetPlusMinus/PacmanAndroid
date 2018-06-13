#include "shader.h"
#include "platform_gl.h"
#include "platform_log.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
 
#define TAG "shaders"
 
static void log_v_fixed_length(const GLchar* source, const GLint length) {
    if (LOGGING_ON) {
        char log_buffer[length + 1];
        memcpy(log_buffer, source, length);
        log_buffer[length] = '\0';
 
        DEBUG_LOG_WRITE_V(TAG, log_buffer);
    }
}
 
static void log_shader_info_log(GLuint shader_object_id) {
    if (LOGGING_ON) {
        GLint log_length;
        glGetShaderiv(shader_object_id, GL_INFO_LOG_LENGTH, &log_length);
        GLchar log_buffer[log_length];
        glGetShaderInfoLog(shader_object_id, log_length, NULL, log_buffer);
 
        DEBUG_LOG_WRITE_V(TAG, log_buffer);
    }
}
 
static void log_program_info_log(GLuint program_object_id) {
    if (LOGGING_ON) {
        GLint log_length;
        glGetProgramiv(program_object_id, GL_INFO_LOG_LENGTH, &log_length);
        GLchar log_buffer[log_length];
        glGetProgramInfoLog(program_object_id, log_length, NULL, log_buffer);
 
        DEBUG_LOG_WRITE_V(TAG, log_buffer);
    }
}

GLuint compile_shader(const GLenum type, const GLchar* source, const GLint length) {
	assert(source != NULL);
    
	// We create a new shader object
	GLuint shader_object_id = glCreateShader(type);
    GLint compile_status;
 
    assert(shader_object_id != 0);
 
	// Pass in the source, compile shader
    glShaderSource(shader_object_id, 1, (const GLchar **)&source, &length);
    glCompileShader(shader_object_id);
    glGetShaderiv(shader_object_id, GL_COMPILE_STATUS, &compile_status);
 
    if (LOGGING_ON) {
        DEBUG_LOG_WRITE_D(TAG, "Results of compiling shader source:");
        log_v_fixed_length(source, length);
        log_shader_info_log(shader_object_id);
    }
 
    assert(compile_status != 0);
	
	// If everything was successful, we then return the shader ID
    return shader_object_id;
}

GLuint link_program(const GLuint vertex_shader, const GLuint fragment_shader) {
	// Creat a id
    GLuint program_object_id = glCreateProgram();
    GLint link_status;
 
    assert(program_object_id != 0);
	
	// ling shaders with id
    glAttachShader(program_object_id, vertex_shader);
    glAttachShader(program_object_id, fragment_shader);
    glLinkProgram(program_object_id);
    glGetProgramiv(program_object_id, GL_LINK_STATUS, &link_status);
 
    if (LOGGING_ON) {
        DEBUG_LOG_WRITE_D(TAG, "Results of linking id:");
        log_program_info_log(program_object_id);
    }
 
    assert(link_status != 0);
	
	// If all was successful, then we return the id object ID
    return program_object_id;
}

// This helper method takes in the source for a vertex shader and a fragment shader, and returns the linked id object.
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

// We can use this method for debugging purposes, if we want some extra info about a id during a specific moment in our rendering code.
GLint validate_program(const GLuint program) {
    if (LOGGING_ON) {
        int validate_status;
 
        glValidateProgram(program);
        glGetProgramiv(program, GL_VALIDATE_STATUS, &validate_status);
        DEBUG_LOG_PRINT_D(TAG, "Results of validating id: %d", validate_status);
        log_program_info_log(program);
        return validate_status;
    }
 
    return 0;
}