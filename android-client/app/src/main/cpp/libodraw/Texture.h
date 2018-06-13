//
// Created by views on 08.06.18.
//

#ifndef ANDROID_CLIENT_TEXTURE_H
#define ANDROID_CLIENT_TEXTURE_H

#include <string>
#include <GLES2/gl2.h>
#include "../platform_asset_utils.h"
#include "../image.h"

namespace OpenDraw {
    class Texture {
    public:
        Texture() = default;

        void loadFromPngAsset(std::string path) {
            const FileData png_file = get_asset_data(path.c_str());
            const RawImageData raw_image_data =
                    get_raw_image_data_from_png(png_file.data, (size_t) png_file.data_length);
            id = load(
                    raw_image_data.width, raw_image_data.height,
                    raw_image_data.gl_color_format, raw_image_data.data);

            release_raw_image_data(&raw_image_data);
            release_asset_data(&png_file);
        }

        GLuint getId() {
            return id;
        }

    private:
        GLuint id;

        GLuint load(
                const GLsizei width, const GLsizei height,
                const GLenum type, const GLvoid* pixels) {
            GLuint texture_object_id;
            glGenTextures(1, &texture_object_id);
            assert(texture_object_id != 0);

            glBindTexture(GL_TEXTURE_2D, texture_object_id);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexImage2D(
                    GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, pixels);
            glGenerateMipmap(GL_TEXTURE_2D);

            glBindTexture(GL_TEXTURE_2D, 0);
            return texture_object_id;
        }
    };
}

#endif //ANDROID_CLIENT_TEXTURE_H