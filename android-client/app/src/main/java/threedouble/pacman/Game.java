package threedouble.pacman;

import android.opengl.GLSurfaceView;
import android.os.Message;

import java.io.IOException;
import java.net.SocketException;

public class Game extends Service {
    Game(MainActivity context) throws SocketException {
        super();
        this.context = context;
    }

    public void start(String name) throws IOException {
        Thread thread = new Thread(this);
        thread.start();

        context.server.Connect(name);
    }

    public boolean isRendererSet() {
        return rendererSet;
    }

    public GLSurfaceView getGLSurfaceView() {
        return glSurfaceView;
    }

    @Override
    protected void Queue(byte[] message) {
        Message msg = context.messageHandler.obtainMessage();
        msg.obj = "Position in queue: " + (message[1] << 8 | message[0]);
        context.messageHandler.sendMessage(msg);
    }

    @Override
    protected void Start(byte[] message) {

        // TODO: Убрать для релиза
        if (glSurfaceView != null) {
            return;
        }

        glSurfaceView = new GLSurfaceView(context);

        if (context.isProbablyEmulator()) {
            glSurfaceView.setEGLConfigChooser(8, 8, 8, 8, 16, 0);
        }

        glSurfaceView.setEGLContextClientVersion(2);
        gameRenderer = new GameRenderer(context.getAssets(), message);
        glSurfaceView.setRenderer(gameRenderer);
        rendererSet = true;

        Message msg = context.viewHandler.obtainMessage();
        msg.obj = glSurfaceView;
        context.viewHandler.sendMessage(msg);
    }

    @Override
    protected void Iteration(byte[] message) {
        GameRenderer.iterateJNI(message);
    }

    @Override
    protected void End(byte[] message) {
        GameRenderer.endJNI(message);
    }

    private GLSurfaceView glSurfaceView;
    private boolean rendererSet;
    private MainActivity context;
    private GameRenderer gameRenderer;
}