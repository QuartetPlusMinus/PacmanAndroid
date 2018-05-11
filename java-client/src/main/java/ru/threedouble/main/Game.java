package ru.threedouble.main;

import ru.threedouble.proto.Service.*;

import java.net.InetAddress;
import java.net.SocketException;

public class Game extends Service {
    Game(InetAddress ipAddress, int port) throws SocketException {
        super(ipAddress, port);
    }

    @Override
    protected void Queue(QueueReply queueReply) {}

    protected void Start(StartReply startReply) {}

    protected void Iteration(IterationReply iterationReply) {}

    protected void End(EndReply endReply) {}


}
