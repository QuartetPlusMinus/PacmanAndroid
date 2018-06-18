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

        void setSize(float height, float width);

        void setTexture(Texture &texture);

        void setTextureSize(float height, float width);

        void init();

        void draw();

        void setZIndex(float index);

        void setPosition(float x, float y);

        void setTexturePosition(float x, float y);


    private:
        ShaderPrograms::TextureProgram program;
        Texture texture;
        GLuint buffer;
        vec2 position;
        vec2 size;
        vec2 texturePosition;
        vec2 tSize;
        float zIndex;

    };
}

#endif //ANDROID_CLIENT_SPRITE_H
