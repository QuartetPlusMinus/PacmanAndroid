package threedouble.pacman.classes;

import java.net.SocketException;

public class Service extends Network{

    Service() throws SocketException {
        super();
    }

    protected void Queue(byte[] message) {}

    protected void Start(byte[] message) {}

    protected void Iteration(byte[] message) {}

    protected void End(byte[] message) {}

    @Override
    protected void switchRequest(byte type, byte[] data, int size) {
        switch (type) {
            case QUEUE:
                Queue(data);
                break;
            case START:
                Start(data);
                break;
            case ITERATION:
                Iteration(data);
                break;
            case END:
                End(data);
                break;
        }
    }

    static private final byte QUEUE = 0;
    static private final byte START = 1;
    static private final byte ITERATION = 2;
    static private final byte END = 3;
}