package threedouble.pacman;

import com.google.protobuf.InvalidProtocolBufferException;

import threedouble.proto.Service.*;

import java.net.InetAddress;
import java.net.SocketException;

class Service extends Network{

    Service() throws SocketException {
        super();
    }

    protected void Queue(QueueReply queueReply) {}

    protected void Start(StartReply startReply) {}

    protected void Iteration(IterationReply iterationReply) {}

    protected void End(EndReply endReply) {}

    @Override
    protected void switchRequest(byte type, byte[] data, int size) throws InvalidProtocolBufferException {
        switch (type) {
            case QUEUE:
                QueueReply queueReply = QueueReply.parseFrom(data);
                Queue(queueReply);
                break;
            case START:
                StartReply startReply = StartReply.parseFrom(data);
                Start(startReply);
                break;
            case ITERATION:
                IterationReply iterationReply = IterationReply.parseFrom(data);
                Iteration(iterationReply);
                break;
            case END:
                EndReply endReply = EndReply.parseFrom(data);
                End(endReply);
                break;
        }
    }

    private final byte QUEUE = 0;
    private final byte START = 1;
    private final byte ITERATION = 2;
    private final byte END = 3;
}