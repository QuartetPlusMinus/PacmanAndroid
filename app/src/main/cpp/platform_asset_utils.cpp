#include "platform_asset_utils.h"
#include <android/asset_manager_jni.h>
#include <cassert>
#include <jni.h>
#include <string>

FileData get_asset_data(const char* relative_path) {
    assert(relative_path != NULL);

    AAsset* asset =
            AAssetManager_open(asset_manager, relative_path
                    , AASSET_MODE_STREAMING);
    assert(asset != NULL);

    return (FileData) { AAsset_getLength(asset), AAsset_getBuffer(asset), asset };
}

void release_asset_data(const FileData* file_data) {
    assert(file_data != NULL);
    assert(file_data->file_handle != NULL);
    AAsset_close((AAsset*)file_data->file_handle);
}

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     com_example_viewsharp_pacman_RendererWrapper
 * Method:    initAssetManagerJNI
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_example_viewsharp_pacman_RendererWrapper_initAssetManagerJNI
        (JNIEnv * env, jobject, jobject java_asset_manager) {

    asset_manager = AAssetManager_fromJava(env, java_asset_manager);

}

#ifdef __cplusplus
}
#endif