//
// Created by views on 08.06.18.
//

#include "Texture.h"

using namespace OpenDraw;

Texture::Texture(AAssetManager *assetManager, std::string path) {
    AAsset *asset = AAssetManager_open(assetManager, path.c_str(), AASSET_MODE_STREAMING);
    assert(asset != NULL);

    const RawImage rawImage(AAsset_getBuffer(asset), (size_t) AAsset_getLength(asset));
    id = load(
            rawImage.width(), rawImage.height(),
            rawImage.glColorFormat(), rawImage.getData());

    AAsset_close(asset);
}

GLuint Texture::getId() const {
    return id;
}

GLuint Texture::load(
        const GLsizei width, const GLsizei height,
        const GLenum type, const GLvoid *pixels) {
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