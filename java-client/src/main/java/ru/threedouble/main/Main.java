package ru.threedouble.main;

import java.io.*;
import java.net.*;
import ru.threedouble.main.Network;
import ru.threedouble.proto.Service.*;

public class Main {

    private static final int port = 31415;

    public static void main(String[] args)
    {

        QueueReply queueReply = QueueReply.newBuilder().build();

        byte[] buffer = queueReply.toByteArray();

        BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
        try {
            DatagramSocket clientSocket = new DatagramSocket();
            InetAddress IPAddress = InetAddress.getByName("localhost");
            byte[] sendData = new byte[1024];
            byte[] receiveData = new byte[1024];
            String sentence = inFromUser.readLine();
            sendData = sentence.getBytes();

//            System.out.println(sentence);

            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, port);
            clientSocket.send(sendPacket);
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
            clientSocket.receive(receivePacket);

            String modifiedSentence = new String(receivePacket.getData());
            System.out.println("FROM SERVER ["+ receiveData.length +"]:" + modifiedSentence);
            clientSocket.close();
        }
        catch (Exception e) {
            System.out.println(e.toString());
        }
    }
}
