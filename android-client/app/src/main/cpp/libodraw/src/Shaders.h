//
// Created by views on 08.06.18.
//

#ifndef ANDROID_CLIENT_SHADERS_H
#define ANDROID_CLIENT_SHADERS_H

#include <GLES2/gl2.h>

namespace OpenDraw {
    namespace Shaders {

        const char TEXTURE_VERTEX_SHADER[] = ""
                "uniform vec2 u_VertexShift;\n"
                "uniform vec2 u_TextureShift;\n"
                "uniform float u_ZIndex;\n"
                "attribute vec4 a_Position;\n"
                "attribute vec2 a_TextureCoordinates;\n"
                "\n"
                "varying vec2 v_TextureCoordinates;\n"
                "\n"
                "void main()\n"
                "{\n"
                "    v_TextureCoordinates = vec2(a_TextureCoordinates.x + u_TextureShift.x, a_TextureCoordinates.y + u_TextureShift.y);\n"
                "    gl_Position = vec4(a_Position.x + u_VertexShift.x, a_Position.y + u_VertexShift.y, a_Position.z - u_ZIndex, 0.5 * a_Position.w);\n"
                "}";

        const char TEXTURE_FRAGMENT_SHADER[] = ""
                "precision mediump float;\n"
                "\n"
                "uniform sampler2D u_TextureUnit;\n"
                "varying vec2 v_TextureCoordinates;\n"
                "\n"
                "void main()\n"
                "{\n"
                "    gl_FragColor = texture2D(u_TextureUnit, v_TextureCoordinates);\n"
                "}";

        const char COLOR_VERTEX_SHADER[] = ""
                "attribute vec4 a_Position;\n"
                "void main()\n"
                "{\n"
                "    gl_Position = a_Position;\n"
                "}";

        const char COLOR_TEXTURE_SHADER[] = ""
                "precision mediump float;\n"
                "uniform vec4 u_Color;\n"
                "void main()\n"
                "{\n"
                "    gl_FragColor = u_Color;\n"
                "}";

        GLuint compile(const GLenum type, const GLchar source[], const GLint length);
    }
}

#endif //ANDROID_CLIENT_SHADERS_H
