//
// Created by viewsharp on 12.04.18.
//

#ifndef PACMANANDROID_ASSET_H
#define PACMANANDROID_ASSET_H

#include <string>
#include <android/asset_manager_jni.h>
#include <cassert>

class Asset {
public:
public:
    Asset(const std::string relativePath, AAssetManager *assetManager){
        fileHandle = AAssetManager_open(assetManager, relativePath.data(), AASSET_MODE_STREAMING);

        assert(fileHandle != NULL);

        length = (unsigned long)AAsset_getLength(fileHandle);
        data = AAsset_getBuffer(fileHandle);
    }

    ~Asset() {
        AAsset_close(fileHandle);
    }

    unsigned long getLength() {
        return length;
    }

    const void* getData() {
        return data;
    }

private:

    unsigned long length;
    const void* data;
    AAsset* fileHandle;
};

#endif //PACMANANDROID_ASSET_H
