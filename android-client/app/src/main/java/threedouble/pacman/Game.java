package threedouble.pacman;

import java.io.IOException;
import java.net.InetAddress;
import java.net.SocketException;

import threedouble.proto.Service.*;

public class Game extends Network{
    Game(InetAddress host) throws SocketException{
        super(host);
        server = new Server(host, 31415);
    }

    public void start(String name) throws IOException {
        ConnectRequest connectRequest = ConnectRequest.newBuilder().setName(name).build();
        server.Connect(connectRequest);
    }

    private Server server;

}
