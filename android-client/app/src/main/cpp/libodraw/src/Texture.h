//
// Created by views on 08.06.18.
//

#ifndef ANDROID_CLIENT_TEXTURE_H
#define ANDROID_CLIENT_TEXTURE_H

#include <string>
#include <GLES2/gl2.h>
#include <android/asset_manager.h>

#include "RawImage.h"

namespace OpenDraw {
    class Texture {
    public:
        Texture(AAssetManager *assetManager, std::string path);

        GLuint id() const;

    private:
        GLuint id_;

        GLuint load(const GLsizei width, const GLsizei height,
                    const GLenum type, const GLvoid *pixels);
    };
}

#endif //ANDROID_CLIENT_TEXTURE_H