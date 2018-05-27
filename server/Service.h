//
// Created by viewsharp on 26.04.18.
//

#ifndef SERVER_PROTOCOL_H
#define SERVER_PROTOCOL_H

#include <service.pb.h>
#include <queue>
#include <google/protobuf/message.h>
#include "Network.h"
#include "GameRoom.h"
#include "Client.h"

using namespace threedouble::proto;

class Service : public Network {
    enum RequestType {
        CONNECT = 0,
        EVENT = 1
    };

public:
    explicit Service(unsigned short port) :
            Network(port) {
    }

private:

    virtual void switchRequest(int type, ip::udp::endpoint &clientEP, const char *data, size_t size) final {
        Client *client;

//        try {
//            unsigned int hass = Client::hash(clientEP);
//            client = clients.at(hass);
//        } catch (std::out_of_range &e) {
//            client = new Client(socket, clientEP);
//            clients.at(client->hash()) = client;
//        }

        if (clients.find(Client::hash(clientEP)) == clients.end()) {
            client = new Client(socket, clientEP);
            clients[client->hash()] = client;
        } else {
            client = clients[Client::hash(clientEP)];
        }

        switch ((RequestType)type) {
            case CONNECT: {
                ConnectMessage connectMsg;
                connectMsg.ParseFromArray(data, (int) size);
                Connect(client, connectMsg);
                break;
            }
            case EVENT: {
                EventMessage eventMsg;
                eventMsg.ParseFromArray(data, (int) size);
                Event(client, eventMsg);
                break;
            }
        }
    }

protected:

    unordered_map<unsigned int, Client *> clients;

    virtual void Connect(Client *client, ConnectMessage &connectMsg) = 0;
    virtual void Event(Client *client, EventMessage &eventMsg) = 0;
};

#endif //SERVER_PROTOCOL_H

