package ru.threedouble.main;

import com.google.protobuf.GeneratedMessageV3;

import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

class Network implements Runnable{

    Network(InetAddress ipAddress, int port) throws SocketException {
        socket = new DatagramSocket();
        this.ipAddress = ipAddress;
        this.port = port;
    }

    @Override
    public void run() {

    }

    protected void switcher(int type, GeneratedMessageV3 request) {}

    private final DatagramSocket socket;
    private final InetAddress ipAddress;
    private final int port;
    private byte[] receiveBuffer = new byte[65536];
}
