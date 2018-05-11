package ru.threedouble.main;

import com.google.protobuf.GeneratedMessageV3;
import ru.threedouble.proto.Service.*;

import java.net.InetAddress;
import java.net.SocketException;

enum RequestType {
    QUEUE,
    START,
    ITERATION,
    END
}

class Service extends Network{

    Service(InetAddress ipAddress, int port) throws SocketException {
        super(ipAddress, port);
    }

    protected void Queue(QueueReply queueReply) {}

    protected void Start(StartReply startReply) {}

    protected void Iteration(IterationReply iterationReply) {}

    protected void End(EndReply endReply) {}

    @Override
    protected void switcher(int type, GeneratedMessageV3 request) {
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