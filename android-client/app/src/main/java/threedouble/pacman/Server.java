package threedouble.pacman;

import threedouble.proto.Service.*;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

class Server{
    class Sender implements Runnable{
        Sender(DatagramSocket socket, DatagramPacket packet) {
            datagramSocket = socket;
            datagramPacket = packet;
            exception = null;
        }

        @Override
        public void run(){
            try {
                datagramSocket.send(datagramPacket);
            }
            catch (IOException e) {
                exception = e;
            }
        }

        public IOException exception;
        private DatagramSocket datagramSocket;
        private DatagramPacket datagramPacket;
    }

    Server(InetAddress host, int port, DatagramSocket socket) throws SocketException {
        this.socket = socket;
        this.host = host;
        this.port = port;
    }

    private final byte CONNECT = 0;
    private final byte EVENT = 1;

    void Connect(ConnectRequest connectRequest) throws IOException {
        sendBytes(CONNECT, connectRequest.toByteArray());
    }

    void Event(EventRequest eventRequest) throws IOException {
        sendBytes(EVENT, eventRequest.toByteArray());
    }

    private void sendBytes(byte type, byte[] bytes) throws IOException {
        byte[] requestBytes = new byte[bytes.length+1];

        requestBytes[0] = type;
        System.arraycopy(bytes, 0, requestBytes, 1, bytes.length);

        DatagramPacket sendPacket = new DatagramPacket(requestBytes, requestBytes.length, host, port);

        Sender sender = new Sender(socket, sendPacket);
        Thread thread = new Thread(sender);
        thread.start();

        try {
            thread.join();
        } catch (InterruptedException e) {
            thread.interrupt();
        }

        if (sender.exception != null) {
            throw sender.exception;
        }
    }

    private final DatagramSocket socket;
    private final InetAddress host;
    private final int port;
}
