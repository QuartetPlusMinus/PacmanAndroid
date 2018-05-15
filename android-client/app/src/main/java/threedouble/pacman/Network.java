package threedouble.pacman;

import com.google.protobuf.GeneratedMessageLite;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

class Network implements Runnable{

    Network(InetAddress ipAddress) throws SocketException {
        socket = new DatagramSocket();
        this.ipAddress = ipAddress;
    }

    @Override
    public void run() {

    }

    protected void switcher(int type, GeneratedMessageLite request) {}

    private final DatagramSocket socket;
    private final InetAddress ipAddress;
    private byte[] receiveBuffer = new byte[65536];
}
