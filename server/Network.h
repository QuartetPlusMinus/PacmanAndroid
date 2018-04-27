//
// Created by viewsharp on 26.04.18.
//

#ifndef SERVER_NETWORK_H
#define SERVER_NETWORK_H

#include <boost/asio.hpp>
#include <cstdlib>
#include <ctime>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

using namespace std;
using namespace boost::asio;

typedef union {
    int id;
    char type;
} Token;

typedef enum {
    REQUEST,
    REPLY,
    SAFE_SEND,
    SAFE_ASK,
    SEND
} MessageType;

static class Message {
public:
    Message(MessageType type, char* data, unsigned int size) :
            initTime(time(nullptr)),
            data(data)
    {
        srand((unsigned int)time(nullptr));
        token.id = rand() << 16 + rand();
        token.type = (char)type;

        this->data = new char[size];
        std::copy(data, data+size, this->data);
    }

    explicit Message(char* buffer) {
        initTime = *(time_t *)buffer;
        buffer += sizeof(time_t);

        token = *(Token *)buffer;
        buffer += sizeof(Token);

        size = *(unsigned int *)buffer ;
        buffer += sizeof(int);

        data = new char[size];
        std::copy(buffer, buffer + size, data);
    }

    ~Message() {
        delete[] data;
    }

    void toBytes(char *buffer) {
        *(time_t *)buffer = initTime;
        buffer += sizeof(time_t);

        *(Token *)buffer = token;
        buffer += sizeof(Token);

        *(unsigned int *)buffer = size;
        buffer += sizeof(int);

        std::copy(data, data + size, buffer);
    }

    unsigned int length() {
        return sizeof(time_t) + sizeof(Token) + sizeof(int) + size;
    }

private:
    time_t initTime;
    Token token;
    char* data;
    unsigned int size;
};


class Network {
public:
    Network(unsigned short port) :
            socket(service, ip::udp::endpoint(ip::udp::v4(), port)) {

        boost::thread(boost::bind([](){
            ip::udp::endpoint ep(ip::udp::v4(), port);
            socket.open(ep.protocol());
            socket.set_option(boost::asio::ip::udp::socket::reuse_address(true));
            socket.bind(ep);
            socket.async_receive_from(buffer(receiveBuffer), ip::udp::endpoint(), on_read);
            service.run();
        }));


    }

    void Request(ip::udp::endpoint &sender_ep, char *data, unsigned int size, char *reply) {
        Message message(REQUEST, data, size);
        char* buff = new char[message.length()];
        message.toBytes(buff);

        socket.send_to(buffer(buff, message.length()), sender_ep);

        delete[] buff;

//        socket.receive_from(buffer(receiveBuffer), sender_ep);
    }

    void SafeSend(ip::udp::endpoint &sender_ep, char *data, unsigned int size) {
        Message message(SAFE_SEND, data, size);
        char* buff = new char[message.length()];
        message.toBytes(buff);

        socket.send_to(buffer(buff, message.length()), sender_ep);

        delete[] buff;
    }

    void Send(ip::udp::endpoint &sender_ep, char *data, unsigned int size) {
        Message message(SEND, data, size);
        char* buff = new char[message.length()];
        message.toBytes(buff);

        socket.send_to(buffer(buff, message.length()), sender_ep);

        delete[] buff;
    }

private:
    io_service service;
    ip::udp::socket socket;

    char receiveBuffer[65536];

    void receiveHandler() {

    }

};

#endif //SERVER_NETWORK_H
