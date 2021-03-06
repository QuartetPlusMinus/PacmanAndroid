package threedouble.pacman.classes;

import android.os.Message;

import java.io.IOException;
import java.net.SocketException;

import threedouble.pacman.MainActivity;

public class Game extends Service {
    public Game(MainActivity context) throws SocketException {
        super();
        this.context = context;
    }

    public void start(String name) throws IOException {
        Thread thread = new Thread(this);
        thread.start();

        context.server.Connect(name);
    }

    @Override
    protected void Queue(byte[] message) {
        Message msg = context.messageHandler.obtainMessage();
        msg.obj = "Position in queue: " + (message[1] << 8 | message[0]);
        context.messageHandler.sendMessage(msg);
    }

    @Override
    protected void Start(byte[] message) {
        Message msg = context.startHandler.obtainMessage();
        msg.obj = message;
        context.startHandler.sendMessage(msg);
    }

    @Override
    protected void Iteration(byte[] message) {
        GameRenderer.iterateJNI(message);
    }

    @Override
    protected void End(byte[] message) {
        context.endGame();
//        GameRenderer.endJNI(message);
    }

    private MainActivity context;
}