package com.example.viewsharp.pacman;

import android.content.res.AssetManager;

public class PlatformFileUtils {
    static {
        System.loadLibrary("game");
    }

    public static void initAssetManager(AssetManager assetManager) {
//        initAssetManagerJNI(assetManager);
    }

//    private static native void initAssetManagerJNI(AssetManager assetManager);
}
