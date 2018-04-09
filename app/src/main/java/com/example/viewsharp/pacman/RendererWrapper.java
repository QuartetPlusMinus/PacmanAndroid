package com.example.viewsharp.pacman;

/*
 * Created by viewsharp on 22.03.18.
 */

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.opengl.GLSurfaceView.Renderer;

import com.example.viewsharp.pacman.platform.*;

public class RendererWrapper implements Renderer {
    static {
        System.loadLibrary("game");
    }

    private final Context context;

    public RendererWrapper(Context context) {
        this.context = context;
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        PlatformFileUtils.init_asset_manager(context.getAssets());
        onSurfaceCreatedJNI();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        onSurfaceChangedJNI(width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        onDrawFrameJNI();
    }

    private static native void onSurfaceCreatedJNI();

    private static native void onSurfaceChangedJNI(int width, int height);

    private static native void onDrawFrameJNI();
}
