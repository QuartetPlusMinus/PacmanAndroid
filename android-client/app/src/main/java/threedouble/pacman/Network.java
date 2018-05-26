package threedouble.pacman;

import com.google.protobuf.GeneratedMessageLite;
import com.google.protobuf.InvalidProtocolBufferException;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;
import java.net.SocketException;

class Network implements Runnable{
    Network() throws SocketException {
        socket = new DatagramSocket();
    }

    @Override
    public void run() {
        listen = true;
        while (listen) {
            DatagramPacket packet = new DatagramPacket(buff, buff.length);

            try {
                socket.receive(packet);
            } catch (IOException e) {
                exception = e;
            }

            byte[] data = new byte[packet.getLength() - 1];
            System.arraycopy(packet.getData(), 1, data, 0, packet.getLength()-1);
            try {
                switchRequest(packet.getData()[0], data, packet.getLength() - 1);
            } catch (InvalidProtocolBufferException e) {
                continue;
            }
        }
    }

    public void stop() {
        listen = false;
    }
    public IOException exception;
    public DatagramSocket getSocket() {
        return socket;
    }

    protected void switchRequest(byte type, byte[] data, int size) throws InvalidProtocolBufferException {}

    private final DatagramSocket socket;
    private boolean listen;
    private byte[] buff = new byte[65536];

}
