//
// Created by viewsharp on 11.04.18.
//

#ifndef PACMANANDROID_GAME_H
#define PACMANANDROID_GAME_H

#include <jni.h>
#include "../cpp/Game.cpp"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     com_example_viewsharp_pacman_RendererWrapper
 * Method:    onSurfaceCreated
 * Signature: ()V
 */
JNIEXPORT void
JNICALL Java_com_example_viewsharp_pacman_RendererWrapper_onSurfaceCreatedJNI (JNIEnv *, jobject);

/*
 * Class:     com_example_viewsharp_pacman_RendererWrapper
 * Method:    onSurfaceChanged
 * Signature: (II)V
 */
JNIEXPORT void
JNICALL Java_com_example_viewsharp_pacman_RendererWrapper_onSurfaceChangedJNI
        (JNIEnv *, jobject, jint width, jint height);

/*
 * Class:     com_example_viewsharp_pacman_RendererWrapper
 * Method:    onDrawFrame
 * Signature: ()V
 */
JNIEXPORT void
JNICALL Java_com_example_viewsharp_pacman_RendererWrapper_onDrawFrameJNI(JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif //PACMANANDROID_GAME_H
