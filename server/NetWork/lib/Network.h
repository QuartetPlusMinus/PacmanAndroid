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

class Network {
public:
    explicit Network(unsigned short port) :
            socket(service, ip::udp::endpoint(ip::udp::v4(), port)),
            listen(false)
    {

        socket.async_receive_from(
                buffer(buff),
                senderEP,
                [this](const boost::system::error_code &err, size_t size) {this->onRead(err, size);});
    }

    void run() {
        listen = true;
        service.run();
    }

    void stop() {
        listen = false;
    }

private:

    void onRead(const boost::system::error_code &err, size_t size) {
        switchRequest(buff[0], senderEP, buff + 1, size - 1);
        if (listen) {
            socket.async_receive_from(
                    buffer(buff),
                    senderEP,
                    [this](const boost::system::error_code &err, size_t size) { this->onRead(err, size); });
        }
    }

    virtual void switchRequest(int type, ip::udp::endpoint &senderEP, const char *data, size_t size) = 0;

    io_service service;
    bool listen;
    char buff[65536];
    ip::udp::endpoint senderEP;

protected:
    Socket socket;

};

#endif //SERVER_NETWORK_H
