package ru.threedouble.main;

import java.io.IOException;
import java.net.*;
import ru.threedouble.proto.Service.*;

public class Main {
    private static final int receiverPort = 27182;
    private static final int initiatorPort = 31415;

    public static void main(String[] args) {
        try {
            loop();
        }
        catch (Exception e) {
            System.out.println(e.toString());
        }
    }

    private static void loop() throws IOException {
        Service service = new Service(InetAddress.getByName("localhost"), receiverPort);
        service.run();

        Server server = new Server(InetAddress.getByName("localhost"), initiatorPort);
        ConnectRequest connectRequest =
                ConnectRequest.newBuilder()
                        .setName("test")
                        .build();
        server.Connect(connectRequest);
    }
}
