package threedouble.pacman.classes;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Server {
    class Sender implements Runnable {
        Sender(DatagramSocket socket, DatagramPacket packet) {
            datagramSocket = socket;
            datagramPacket = packet;
            exception = null;
        }

        @Override
        public void run() {
            try {
                datagramSocket.send(datagramPacket);
            } catch (IOException e) {
                exception = e;
            }
        }

        IOException exception;
        private DatagramSocket datagramSocket;
        private DatagramPacket datagramPacket;
    }

    public Server(InetAddress host, int port, DatagramSocket socket) {
        this.socket = socket;
        this.host = host;
        this.port = port;
    }

    void Connect(String username) throws IOException{
        int length = username.length();
        ByteArrayOutputStream outputStream = new ByteArrayOutputStream();

        outputStream.write((byte)length);
        outputStream.write((byte)length>>>8);
        outputStream.write((byte)length>>>16);
        outputStream.write((byte)length>>>24);
        outputStream.write(username.getBytes());

        sendBytes(CONNECT, outputStream.toByteArray());
    }

    void Event(byte direction) throws IOException {
        sendBytes(EVENT, new byte[] {direction});
    }

    private void sendBytes(byte type, byte[] bytes) throws IOException {
        byte[] requestBytes = new byte[bytes.length + 1];

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

    static private final byte CONNECT = 0;
    static private final byte EVENT = 1;

    private final DatagramSocket socket;
    private final InetAddress host;
    private final int port;
}
