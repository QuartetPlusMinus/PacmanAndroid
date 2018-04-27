package ru.threedouble.main;

import ru.threedouble.proto.Service.*;
import ru.threedouble.main.Network;

import java.net.InetAddress;
import java.net.SocketException;

class Service extends Network{

    public Service(InetAddress ipAddress, int port) throws SocketException {
        super(ipAddress, port);
    }

    public void Connect(ConnectRequest connectRequest) {

    }

    public void Event(EventRequest eventRequest) {

    }

    // ----------------------------------------------------------------------------------------------------------------

    private void Queue(QueueReply queueReply) {

    }

    private void Start(StartReply startReply) {

    }

    private void Iteration(IterationReply iterationReply) {

    }

    private void End(EndReply endReply) {

    }

}