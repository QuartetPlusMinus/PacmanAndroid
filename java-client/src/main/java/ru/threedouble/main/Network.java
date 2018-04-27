package ru.threedouble.main;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

class Message {

}

class Network {

    Network(InetAddress ipAddress, int port) throws SocketException {
        socket = new DatagramSocket(); // throws SocketException
        this.ipAddress = ipAddress;
        this.port = port;
    }

    public byte[] Request(byte[] data) throws IOException {
        DatagramPacket sendPacket = new DatagramPacket(data, data.length, ipAddress, port);
        socket.send(sendPacket); // throws IOException

        DatagramPacket receivePacket = new DatagramPacket(receiveBuffer, receiveBuffer.length);
        socket.receive(receivePacket);

        return receivePacket.getData();
    }

    public void SafeSend(byte[] data) throws IOException {
        DatagramPacket sendPacket = new DatagramPacket(data, data.length, ipAddress, port);
        socket.send(sendPacket); // throws IOException

    }

    public void Send(byte[] data) throws IOException {
        DatagramPacket sendPacket = new DatagramPacket(data, data.length, ipAddress, port);
        socket.send(sendPacket); // throws IOException
    }

    private final DatagramSocket socket;
    private final InetAddress ipAddress;
    private final int port;
    private byte[] receiveBuffer = new byte[65536];
}
