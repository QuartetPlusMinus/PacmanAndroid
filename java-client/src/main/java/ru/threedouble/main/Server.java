package ru.threedouble.main;

import ru.threedouble.proto.Service.*;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

class Server {
    Server(InetAddress ipAddress, int port) throws SocketException {
        socket = new DatagramSocket();
        this.ipAddress = ipAddress;
        this.port = port;
    }

    void Connect(ConnectRequest connectRequest) throws IOException {
        byte[] data = connectRequest.toByteArray();
        DatagramPacket sendPacket = new DatagramPacket(data, data.length, ipAddress, port);
        socket.send(sendPacket);
    }

//    void Event(EventRequest eventRequest) {
//
//    }

    private final DatagramSocket socket;
    private final InetAddress ipAddress;
    private final int port;
}
