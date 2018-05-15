package threedouble.pacman;

import com.google.protobuf.GeneratedMessageLite;
import threedouble.proto.Service.*;

import java.net.InetAddress;
import java.net.SocketException;

class Service extends Network{

    enum RequestType {
        QUEUE,
        START,
        ITERATION,
        END
    }

    Service(InetAddress ipAddress) throws SocketException {
        super(ipAddress);
    }

    protected void Queue(QueueReply queueReply) {}

    protected void Start(StartReply startReply) {}

    protected void Iteration(IterationReply iterationReply) {}

    protected void End(EndReply endReply) {}

    @Override
    protected void switcher(int type, GeneratedMessageLite request) {
        switch (RequestType.values()[type]) {
            case QUEUE:
                Queue((QueueReply)request);
                break;
            case START:
                Start((StartReply) request);
                break;
            case ITERATION:
                Iteration((IterationReply) request);
                break;
            case END:
                End((EndReply) request);
                break;

        }
    }
}