//
// Created by viewsharp on 01.05.18.
//

#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H

#include <boost/asio.hpp>
#include <boost/thread.hpp>

using namespace boost::asio;

struct Token {
    Token() :
            rnd(rand() << 16 + rand()),
            tm((int) time(nullptr)) {
    }

    int rnd;
    int tm;

    void toBytes(char* buff) {
        *(int*)buff = rnd;
        buff += 4;
        *(int*)buff = tm;
    }
};




class Socket : public ip::udp::socket {
public:
    Socket(boost::asio::io_context &context, const ip::udp::endpoint &ep) :
            ip::udp::socket(context, ep) {
    }

//    template<typename ConstBufferSequence>
//    void reliable_send_to(const ConstBufferSequence &buffers, const endpoint_type &destination) {
//        bool wait_response = true;
//        Token token;
//
//        boost::thread thread(boost::bind(reliable_listen_worker, &wait_response, token, destination));
//
//        size_t buffSize = sizeof(Token) + buffers[1]
//        char *buff = new char[buffSize];
//        token.toBytes(buff);
//        std::copy(buffers[0], buffers[0]+buffers[1], buff+8);
//
//        while (wait_response) {
//            send_to(buffer(buff, buffSize), destination);
//            boost::this_thread::sleep(10);
//        }
//
//
//    }

//    template<typename ConstBufferSequence>
//    void receive_from(const ConstBufferSequence &buffers, const endpoint_type &destination) {
//
//    }


private:

//    void reliable_listen_worker(Token token, bool *wait_response, const endpoint_type &destination) {
//        char buff[65536];
//        while (true) {
//            ip::udp::endpoint senderEP;
//            size_t size = receive_from(buffer(buff), senderEP);
//
//            if (senderEP.address() == destination.address() and token == buff) {
//                break;
//            }
//        }
//
//        *wait_response = false;
//    }

};

#endif //SERVER_SOCKET_H
