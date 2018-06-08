#include <jni.h>
#include <android/asset_manager_jni.h>

#include "macros.h"
#include "program.h"
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
    game.onSurfaceChanged((int)width, (int)height);
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
        (JNIEnv *env, jobject, jbyteArray message) {
    jboolean isCopy = JNI_FALSE;
    game.start((char*)env->GetByteArrayElements(message, &isCopy), (size_t)env->GetArrayLength(message));
}

/*
 * Class:     com_example_viewsharp_pacman_RendererWrapper
 * Method:    iterate
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_threedouble_pacman_GameRenderer_iterateJNI
        (JNIEnv *env, jobject, jbyteArray message) {
    jboolean isCopy = JNI_FALSE;
    game.iterate((char*)env->GetByteArrayElements(message, &isCopy), (size_t)env->GetArrayLength(message));
}

/*
 * Class:     com_example_viewsharp_pacman_RendererWrapper
 * Method:    end
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_threedouble_pacman_GameRenderer_endJNI
        (JNIEnv *env, jobject, jbyteArray message) {
    jboolean isCopy = JNI_FALSE;
    game.iterate((char*)env->GetByteArrayElements(message, &isCopy), (size_t)env->GetArrayLength(message));
}

#ifdef __cplusplus
}
#endif
#endif _Included_com_example_viewsharp_pacman_GameRenderer