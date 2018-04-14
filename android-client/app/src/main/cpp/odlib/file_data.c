//
// Created by viewsharp on 12.04.18.
//

#include "file_data.h"
#include <assert.h>
#include <stdint.h>

FileData create_file_data(const char* relative_path, AAssetManager *asset_manager) {
    assert(relative_path != NULL);

    AAsset* asset =
            AAssetManager_open(asset_manager, relative_path
                    , AASSET_MODE_STREAMING);
    assert(asset != NULL);

    return (FileData) { AAsset_getLength(asset), AAsset_getBuffer(asset), asset };
}
