package threedouble.pacman;

/*
 * Created by viewsharp on 22.03.18.
 */

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.content.res.AssetManager;
import android.opengl.GLSurfaceView.Renderer;

public class GameRenderer implements Renderer {
    static {
        System.loadLibrary("game");
    }

    GameRenderer(AssetManager assetManager, byte[] startMessage) {
        initAssetManagerJNI(assetManager);
        startJNI(startMessage);
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
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

    public static native void initAssetManagerJNI(AssetManager assetManager);

    public static native void onSurfaceCreatedJNI();

    public static native void onSurfaceChangedJNI(int width, int height);

    public static native void onDrawFrameJNI();

    public static native void startJNI(byte[] message);

    public static native void iterateJNI(byte[] message);

    public static native void endJNI(byte[] message);


}
