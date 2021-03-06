package threedouble.pacman.classes;

//import com.google.protobuf.InvalidProtocolBufferException;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

class Network implements Runnable{
    Network() throws SocketException {
        socket = new DatagramSocket(27182);
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
            switchRequest(packet.getData()[0], data, packet.getLength() - 1);
        }
    }

    public void stop() {
        listen = false;
    }
    public IOException exception;
    public DatagramSocket getSocket() {
        return socket;
    }

    protected void switchRequest(byte type, byte[] data, int size) {}

    private final DatagramSocket socket;
    private boolean listen;
    private byte[] buff = new byte[65536];

}
