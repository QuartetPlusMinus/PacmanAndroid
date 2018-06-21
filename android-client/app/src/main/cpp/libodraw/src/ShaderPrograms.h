//
// Created by views on 08.06.18.
//

#ifndef ANDROID_CLIENT_SHADERPROGRAM_H
#define ANDROID_CLIENT_SHADERPROGRAM_H

#include <GLES2/gl2.h>
#include <cassert>
#include "Shaders.h"

namespace OpenDraw {
    namespace ShaderPrograms {
        class ShaderProgram {
        public:
            ShaderProgram() = default;

            GLuint getProgram();

        protected:
            GLuint id;

            void build(const GLchar vertex_shader_source[],
                       const GLint vertex_shader_source_length,
                       const GLchar fragment_shader_source[],
                       const GLint fragment_shader_source_length);

            void link(const GLuint &vertex_shader, const GLuint &fragment_shader);
        };

        class TextureProgram : public ShaderProgram {
        public:
            TextureProgram() = default;

            void init();

            GLint getAPosition();

            GLint getATextureCoordinates();

            GLint getUVertexShift();

            GLint getUTextureShift();

            GLint getUTextureUnit();

            GLint getUZIndex();


        private:
            GLint aPosition;
            GLint aTextureCoordinates;
            GLint uVertexShift;
            GLint uTextureShift;
            GLint uTextureUnit;
            GLint uZIndex;
        };

        class ColorProgram : public ShaderProgram {
        public:
            ColorProgram() = default;

        private:
            GLint a_position_location;
            GLint u_color_location;
        };
    }
}

#endif //ANDROID_CLIENT_SHADERPROGRAM_H
