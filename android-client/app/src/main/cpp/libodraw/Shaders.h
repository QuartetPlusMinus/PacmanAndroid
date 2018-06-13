//
// Created by views on 08.06.18.
//

#ifndef ANDROID_CLIENT_SHADERS_H
#define ANDROID_CLIENT_SHADERS_H

#include <GLES2/gl2.h>

namespace OpenDraw {
    namespace Shaders {

        static const char textureVertexShader[] = ""
                "uniform vec2 u_VertexShift;\n"
                "uniform vec2 u_TextureShift;\n"
                "attribute vec4 a_Position;\n"
                "attribute vec2 a_TextureCoordinates;\n"
                "\n"
                "varying vec2 v_TextureCoordinates;\n"
                "\n"
                "void main()\n"
                "{\n"
                "    v_TextureCoordinates = vec2(a_TextureCoordinates.x + u_TextureShift.x, a_TextureCoordinates.y + u_TextureShift.y);\n"
                "    gl_Position = vec4(a_Position.x + u_VertexShift.x, a_Position.y + u_VertexShift.y, a_Position.z, a_Position.w);\n"
                "}";

        static const char textureFragmentShader[] = ""
                "precision mediump float;\n"
                "\n"
                "uniform sampler2D u_TextureUnit;\n"
                "varying vec2 v_TextureCoordinates;\n"
                "\n"
                "void main()\n"
                "{\n"
                "    gl_FragColor = texture2D(u_TextureUnit, v_TextureCoordinates);\n"
                "}";

        static const char colorVertexShader[] = ""
                "attribute vec4 a_Position;\n"
                "void main()\n"
                "{\n"
                "    gl_Position = a_Position;\n"
                "}";

        static const char colorFragmentShader[] = ""
                "precision mediump float;\n"
                "uniform vec4 u_Color;\n"
                "void main()\n"
                "{\n"
                "    gl_FragColor = u_Color;\n"
                "}";

        GLuint compile(const GLenum type, const GLchar* source, const GLint length);
    }
}

#endif //ANDROID_CLIENT_SHADERS_H
