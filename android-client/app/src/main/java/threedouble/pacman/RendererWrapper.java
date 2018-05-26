package threedouble.pacman;

/*
 * Created by viewsharp on 22.03.18.
 */

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.content.res.AssetManager;
import android.opengl.GLSurfaceView.Renderer;

import java.util.List;

import threedouble.proto.Service.*;

public class RendererWrapper implements Renderer {
    static {
        System.loadLibrary("game");
    }


    public RendererWrapper(Context context) {
        this.context = context;
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {

        AssetManager assetManager = context.getAssets();
        initAssetManagerJNI(assetManager);
        onSurfaceCreatedJNI();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
//        onSurfaceChangedJNI(width, height);

    }

    @Override
    public void onDrawFrame(GL10 gl) {
        onDrawFrameJNI();
    }

    public void start() {startJNI();}
    public void iterate() {iterateJNI();}
    public void end() {endJNI();}

    public void setUnits(List<UnitInit> units) {
        this.units = units;
    }

//    public List<UnitInit> getUnits() {
//        return units;
//    }

    public  UnitInit getUnit(int index) {
        return units.get(index);
    }

    public int getUnitCount() {
        return units.size();
    }

    private List<UnitInit> units;

    private static native void initAssetManagerJNI(AssetManager assetManager);

    private static native void onSurfaceCreatedJNI();

    private static native void onSurfaceChangedJNI(int width, int height);

    private static native void onDrawFrameJNI();

    private static native void startJNI();

    private static native void iterateJNI();

    private static native void endJNI();

    private final Context context;

}
