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
    Game(MainActivity context) throws SocketException{
        super();
        this.context = context;
    }

    public void start(String name, InetAddress host) throws IOException {
        server = new Server(host, 31415, getSocket());

        Thread thread = new Thread(this);
        thread.start();

        ConnectMessage connectRequest = ConnectMessage.newBuilder().setName(name).build();
        server.Connect(connectRequest);
    }

    public boolean isRendererSet() {
        return rendererSet;
    }

    public GLSurfaceView getGLSurfaceView() {
        return glSurfaceView;
    }

    @Override
    protected void Queue(QueueMessage queueReply) {
        Message msg = context.messageHandler.obtainMessage();
        msg.obj = "Position in queue: " + queueReply.getPosition();
        context.messageHandler.sendMessage(msg);
    }

    @Override
    protected void Start(StartMessage startReply) {

        glSurfaceView = new GLSurfaceView(context);

        if (context.isProbablyEmulator()) {
            // Avoids crashes on startup with some emulator images.
            glSurfaceView.setEGLConfigChooser(8, 8, 8, 8, 16, 0);
        }

        glSurfaceView.setEGLContextClientVersion(2);
        rendererWrapper = new RendererWrapper(context);
        glSurfaceView.setRenderer(rendererWrapper);
        rendererSet = true;

        Message msg = context.viewHandler.obtainMessage();
        msg.obj = glSurfaceView;
        context.viewHandler.sendMessage(msg);

//        rendererWrapper.units = new UnitInit[startReply.getUnitCount()];
//        for (int i = 0; i < startReply.getUnitCount(); i++) {
//            rendererWrapper.units[i] = startReply.getUnit(i);
//        }
//        startReply.getUnitList()
        rendererWrapper.setUnits(startReply.getUnitList());

        rendererWrapper.start();
    }

    @Override
    protected void Iteration(IterationMessage iterationReply) {
        rendererWrapper.iterate();
    }

    @Override
    protected void End(EndMessage endReply) {
        rendererWrapper.end();

    }

    private Server server;
    private GLSurfaceView glSurfaceView;
    private boolean rendererSet;
    private MainActivity context;
    RendererWrapper rendererWrapper;
}
