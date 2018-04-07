package com.example.viewsharp.pacman;

/*
 * Created by viewsharp on 22.03.18.
 */

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.Matrix;
import android.content.Context;
import android.opengl.GLSurfaceView.Renderer;


public class RendererWrapper implements Renderer {
    static {
        System.loadLibrary("game");
    }

    private final Context context;

    public RendererWrapper(Context context) {
        this.context = context;
    }

    private float[] mViewMatrix = new float[16];

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {

        // подключим текстуру
//        GLES20.glActiveTexture(GLES20.GL_TEXTURE0);
//        GLES20.glBindTexture(GLES20.GL_TEXTURE_2D, R.drawable.man);

//        Matrix.setLookAtM(mViewMatrix, 0,
//                0.0f, 0.0f, 1.0f,
//                0.0f, 0.0f, -5.0f,
//                0.0f, 1.0f, 0.0f // up:  x, y, z
//        );
        onSurfaceCreated();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        onSurfaceChanged(width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        onDrawFrame();
    }

    private native void onSurfaceCreated();

    private native void onSurfaceChanged(int width, int height);

    private native void onDrawFrame();

}
