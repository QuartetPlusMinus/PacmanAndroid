//
// Created by viewsharp on 26.04.18.
//

#ifndef SERVER_PROTOCOL_H
#define SERVER_PROTOCOL_H

#include <queue>
#include <unordered_map>
#include "Network.h"
#include "GameRoom.h"
#include "Client.h"

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

        std::string data_string(data, size);

        if (clients.count(Client::hash(clientEP)) == 0) {
            client = new Client(socket, clientEP);
            clients[client->hash()] = client;
        } else {
            client = clients[Client::hash(clientEP)];
        }

        switch ((RequestType)type) {
            case CONNECT: {
                Messages::ConnectMessage connectMsg;
                connectMsg.parseFromString(data_string);
                Connect(client, connectMsg);
                break;
            }
            case EVENT: {
                Messages::EventMessage eventMsg;
                eventMsg.parseFromString(data_string);
                Event(client, eventMsg);
                break;
            }
        }
    }

protected:

    unordered_map<unsigned int, Client *> clients;

    virtual void Connect(Client *client, Messages::ConnectMessage &connectMsg) = 0;
    virtual void Event(Client *client, Messages::EventMessage &eventMsg) = 0;
};

#endif //SERVER_PROTOCOL_H

