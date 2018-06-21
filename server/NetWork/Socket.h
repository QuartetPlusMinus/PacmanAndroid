//
// Created by viewsharp on 01.05.18.
//

#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H

#include <boost/asio.hpp>
#include <boost/thread.hpp>

using namespace boost::asio;

class Socket : public ip::udp::socket {
public:
    Socket(boost::asio::io_context &context, const ip::udp::endpoint &ep) :
            ip::udp::socket(context, ep) {
    }
private:
};

#endif //SERVER_SOCKET_H
