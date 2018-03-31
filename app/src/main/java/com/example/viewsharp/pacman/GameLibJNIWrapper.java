package com.example.viewsharp.pacman;

/**
 * Created by viewsharp on 22.03.18.
 */

public class GameLibJNIWrapper {
    static {
        System.loadLibrary("game");
    }

    public static native void on_surface_created();

    public static native void on_surface_changed(int width, int height);

    public static native void on_draw_frame();
}
