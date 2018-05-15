package threedouble.pacman;

import android.opengl.GLSurfaceView;
import android.os.Handler;
import android.os.Message;
import android.widget.TextView;

import java.io.IOException;
import java.net.InetAddress;
import java.net.SocketException;

import threedouble.proto.Service.*;

public class Game extends Service{
    Game(InetAddress host, MainActivity context, Handler messageHandler) throws SocketException{
        super(host);
        this.messageHandler = messageHandler;
        this.context = context;
        server = new Server(host, 31415, getSocket());
    }

    public void start(String name) throws IOException {
        Thread thread = new Thread(this);
        thread.start();

        ConnectRequest connectRequest = ConnectRequest.newBuilder().setName(name).build();
        server.Connect(connectRequest);
    }

    public boolean isRendererSet() {
        return rendererSet;
    }

    public GLSurfaceView getGLSurfaceView() {
        return glSurfaceView;
    }

    @Override
    protected void Queue(QueueReply queueReply) {
//        context.log("Position in queue: " + queueReply.getPosition());
        Message msg = messageHandler.obtainMessage();
        msg.obj = "Position in queue: " + queueReply.getPosition();
        messageHandler.sendMessage(msg);
    }

    @Override
    protected void Start(StartReply startReply) {

        glSurfaceView = new GLSurfaceView(context);

        if (context.isProbablyEmulator()) {
            // Avoids crashes on startup with some emulator images.
            glSurfaceView.setEGLConfigChooser(8, 8, 8, 8, 16, 0);
        }

        glSurfaceView.setEGLContextClientVersion(2);
        glSurfaceView.setRenderer(new RendererWrapper(context));
        rendererSet = true;
        context.setContentView(glSurfaceView);
    }

    @Override
    protected void Iteration(IterationReply iterationReply) {

    }

    @Override
    protected void End(EndReply endReply) {

    }

    private Handler messageHandler;
    private Server server;
    private GLSurfaceView glSurfaceView;
    private boolean rendererSet;
    private MainActivity context;
}
