//
// Created by views on 08.06.18.
//

#ifndef ANDROID_CLIENT_SPRITE_H
#define ANDROID_CLIENT_SPRITE_H

#include <GLES2/gl2.h>
#include "Texture.h"
#include "ShaderPrograms.h"
#include "linmath.h"

#define BUFFER_OFFSET(i) ((void*)(i))

namespace OpenDraw {
    class Sprite {
    public:
        explicit Sprite();

        void init();

        void draw();

        void setPosition(float x, float y);

        void setSize(float width, float height);

        void setTexture(Texture &texture);

        void setTexturePosition(float x, float y);

        void setTextureSize(float width, float height);


    private:
        ShaderPrograms::TextureProgram program;
        Texture texture;
        GLuint buffer;
        vec2 position;
        vec2 size;
        vec2 texturePosition;
        vec2 textureSize;

    };
}

#endif //ANDROID_CLIENT_SPRITE_H
