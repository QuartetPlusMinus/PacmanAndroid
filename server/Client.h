//
// Created by viewsharp on 27.04.18.
//

#ifndef SERVER_CLIENT_H
#define SERVER_CLIENT_H

#include <service.pb.h>
#include "Socket.h"

using namespace ru::threedouble::proto;

class Client {
public:
    Client(Socket &socket, ip::udp::endpoint &ep) :
        socket(socket),
        ep(ep)
    {

    }

    void Queue(QueueReply queueReply) {

    }

    void Start(StartReply startReply) {

    }

    void Iteration(IterationReply iterationReply) {

    }

    void End(EndReply endReply) {

    }

private:
    Socket &socket;
    ip::udp::endpoint ep;
};

#endif //SERVER_CLIENT_H
