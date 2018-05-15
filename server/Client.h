//
// Created by viewsharp on 27.04.18.
//

#ifndef SERVER_CLIENT_H
#define SERVER_CLIENT_H

#include <string>
#include <service.pb.h>
#include "Socket.h"

using namespace ru::threedouble::proto;

class Client {
    enum RequestType {
        QUEUE = 0,
        START = 1,
        ITERATION = 2,
        END = 3
    };

public:
    Client(Socket &socket, ip::udp::endpoint &ep) :
            socket(socket),
            ep(ep) {

    }

    void Queue(QueueReply &queueReply) {
        std::string bytes;
        queueReply.SerializeToString(&bytes);
        sendBytes(QUEUE, bytes);
    }

    void Start(StartReply &startReply) {
        std::string bytes;
        startReply.SerializeToString(&bytes);
        sendBytes(START, bytes);
    }

    void Iteration(IterationReply &iterationReply) {
        std::string bytes;
        iterationReply.SerializeToString(&bytes);
        sendBytes(ITERATION, bytes);
    }

    void End(EndReply &endReply) {
        std::string bytes;
        endReply.SerializeToString(&bytes);
        sendBytes(END, bytes);
    }

private:

    void sendBytes(char type, std::string &bytes) {
        socket.send_to(buffer(type + bytes), ep);
        std::string some = type + bytes;
        std::cout << "Send [" << some << "] to "<< ep.address() << ':' << ep.port() << std::endl;
    }

    Socket &socket;
    ip::udp::endpoint ep;
};

#endif //SERVER_CLIENT_H
