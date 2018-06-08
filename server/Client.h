//
// Created by viewsharp on 27.04.18.
//

#ifndef SERVER_CLIENT_H
#define SERVER_CLIENT_H

#include <string>

#include "../common/Messages/Messages.h"
#include "Socket.h"

static std::hash<std::string> getHshFromSrting;

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

    void Queue(Messages::QueueMessage &queueMsg) const {
        std::string bytes;
        queueMsg.serializeToString(bytes);
        sendBytes(QUEUE, bytes);
    }

    void Start(Messages::StartMessage &startMsg) const{
        std::string bytes;
        startMsg.serializeToString(bytes);
        sendBytes(START, bytes);
    }

    void Iteration(Messages::IterationMessage &iterationMsg) const {
        std::string bytes;
        iterationMsg.serializeToString(bytes);
        sendBytes(ITERATION, bytes);
    }

    void End(Messages::EndMessage &endMsg) const {
        std::string bytes;
        endMsg.serializeToString(bytes);
        sendBytes(END, bytes);
    }



    void setUsername(const std::string &username) {
        this->username = username;
    }

    std::string getUsername() const{
        return username;
    }

    unsigned int hash() {
        return hash(ep);
    }

    static unsigned int hash(ip::udp::endpoint &ep) {
        return (unsigned int)getHshFromSrting(ep.address().to_string()) + ep.port();
    }


private:

    void sendBytes(char type, std::string &bytes) const {
        socket.send_to(buffer(type + bytes), ep);
        std::string some = type + bytes;
//        std::cout << "Send [" << some << "] to "<< ep.address() << ':' << ep.port() << std::endl;
    }

    Socket &socket;
    ip::udp::endpoint ep;
    std::string username;
};

#endif //SERVER_CLIENT_H
