#include "buffer.h"
#include "platform_gl.h"
#include <assert.h>
#include <stdlib.h>
 
GLuint create_vbo(const GLsizeiptr size, const GLvoid* data, const GLenum usage) {
    assert(data != NULL);
	
	// generate new OpenGL vertex buffer object (vbo)
	// генерация нового объекта OpenGL vertex buffer object (vbo)
    GLuint vbo; 
    glGenBuffers(1, &vbo); 
    assert(vbo != 0);
 
	// bind to vbo and upload the data from 'data' into the VBO
	// привязка vdo и загрузка данных из data в объект vbo
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
 
    return vbo;
}
