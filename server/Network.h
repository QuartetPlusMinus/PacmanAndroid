//
// Created by viewsharp on 26.04.18.
//

#ifndef SERVER_NETWORK_H
#define SERVER_NETWORK_H

#include <boost/asio.hpp>
#include <cstdlib>
#include <ctime>

#include "Client.h"
#include "Socket.h"

using namespace std;
using namespace boost::asio;

typedef union {
    int id;
    char type;
} Token;

class Network {
public:
    explicit Network(unsigned short port) :
            socket(service, ip::udp::endpoint(ip::udp::v4(), port)),
            listen(false) {
    }

    void run() {
        while (listen) {
            ip::udp::endpoint sender_ep;
            socket.receive_from(buffer(buff), sender_ep);
        }
    }

private:

    virtual void switcher(int type, Client client, const void* request) = 0;

    io_service service;
    Socket socket;

    char buff[65536];
    bool listen;

};

#endif //SERVER_NETWORK_H
