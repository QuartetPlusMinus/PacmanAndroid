#include <jni.h>
#include <android/asset_manager_jni.h>
#include <Serialization/Messages.h>

#include "Game.h"

/* Header for class com_example_viewsharp_pacman_RendererWrapper */

#ifndef _Included_com_example_viewsharp_pacman_GameRenderer
#define _Included_com_example_viewsharp_pacman_GameRenderer

#ifdef __cplusplus
extern "C" {
#endif

#define JNI_FALSE  0
#define JNI_TRUE   1

static Game game;

/*
 * Class:     com_example_viewsharp_pacman_RendererWrapper
 * Method:    onSurfaceCreated
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_threedouble_pacman_GameRenderer_onSurfaceCreatedJNI
        (JNIEnv *, jobject) {
    game.onSurfaceCreated();
}

/*
 * Class:     com_example_viewsharp_pacman_RendererWrapper
 * Method:    onSurfaceChanged
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_threedouble_pacman_GameRenderer_onSurfaceChangedJNI
        (JNIEnv *, jobject, jint width, jint height) {
    game.onSurfaceChanged((int) width, (int) height);
}

/*
 * Class:     com_example_viewsharp_pacman_RendererWrapper
 * Method:    onDrawFrame
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_threedouble_pacman_GameRenderer_onDrawFrameJNI
        (JNIEnv *, jobject) {
    game.onDrawFrame();
}

/*
 * Class:     com_example_viewsharp_pacman_RendererWrapper
 * Method:    start
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_threedouble_pacman_GameRenderer_startJNI
        (JNIEnv *env, jobject, jbyteArray msgBytes) {
    jboolean isCopy = JNI_FALSE;
    std::string message((char *) env->GetByteArrayElements(msgBytes, &isCopy),
                        (size_t) env->GetArrayLength(msgBytes));
    Messages::StartMessage startMessage;
    startMessage.parseFromString(message);
    game.start(startMessage);
}

/*
 * Class:     com_example_viewsharp_pacman_RendererWrapper
 * Method:    iterate
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_threedouble_pacman_GameRenderer_iterateJNI
        (JNIEnv *env, jobject, jbyteArray msgBytes) {
    if (not game.isStarted()) {
        return;
    }

    jboolean isCopy = JNI_FALSE;
    std::string message((char *) env->GetByteArrayElements(msgBytes, &isCopy),
                        (size_t) env->GetArrayLength(msgBytes));
    Messages::IterationMessage iterationMessage;
    iterationMessage.parseFromString(message);
    game.iterate(iterationMessage);
}

/*
 * Class:     com_example_viewsharp_pacman_RendererWrapper
 * Method:    end
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_threedouble_pacman_GameRenderer_endJNI
        (JNIEnv *env, jobject, jbyteArray msgBytes) {
    jboolean isCopy = JNI_FALSE;
    std::string message((char *) env->GetByteArrayElements(msgBytes, &isCopy),
                        (size_t) env->GetArrayLength(msgBytes));
    Messages::EndMessage endMessage;
    endMessage.parseFromString(message);
    game.end(endMessage);
}

/*
 * Class:     com_example_viewsharp_pacman_RendererWrapper
 * Method:    setAssetManagerJNI
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_threedouble_pacman_GameRenderer_setAssetManagerJNI
        (JNIEnv *env, jobject, jobject java_asset_manager) {
    game.setAssertManager(AAssetManager_fromJava(env, java_asset_manager));
}

#ifdef __cplusplus
}
#endif
#endif // _Included_com_example_viewsharp_pacman_GameRenderer