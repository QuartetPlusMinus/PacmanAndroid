package threedouble.pacman;

import com.google.protobuf.InvalidProtocolBufferException;

import threedouble.proto.Service.*;

import java.net.InetAddress;
import java.net.SocketException;

class Service extends Network{

    Service() throws SocketException {
        super();
    }

    protected void Queue(QueueMessage queueReply) {}

    protected void Start(StartMessage startReply) {}

    protected void Iteration(IterationMessage iterationReply) {}

    protected void End(EndMessage endReply) {}

    @Override
    protected void switchRequest(byte type, byte[] data, int size) throws InvalidProtocolBufferException {
        switch (type) {
            case QUEUE:
                QueueMessage queueReply = QueueMessage.parseFrom(data);
                Queue(queueReply);
                break;
            case START:
                StartMessage startReply = StartMessage.parseFrom(data);
                Start(startReply);
                break;
            case ITERATION:
                IterationMessage iterationReply = IterationMessage.parseFrom(data);
                Iteration(iterationReply);
                break;
            case END:
                EndMessage endReply = EndMessage.parseFrom(data);
                End(endReply);
                break;
        }
    }

    private final byte QUEUE = 0;
    private final byte START = 1;
    private final byte ITERATION = 2;
    private final byte END = 3;
}