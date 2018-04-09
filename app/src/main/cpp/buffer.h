#include "platform_gl.h"
 
#define BUFFER_OFFSET(i) ((void*)(i))

// upload data intu a vertex buffer object
GLuint create_vbo(const GLsizeiptr size, const GLvoid* data, const GLenum usage); 
