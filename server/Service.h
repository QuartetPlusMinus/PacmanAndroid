//
// Created by viewsharp on 26.04.18.
//

#ifndef SERVER_PROTOCOL_H
#define SERVER_PROTOCOL_H

#include <service.pb.h>
#include <queue>
#include "Network.h"
#include "GameRoom.h"
#include "Client.h"

typedef enum {
    CONNECT,
    EVENT
} RequestType;

class Service : public Network {
public:
    Service(unsigned short port) :
            Network(port) {
    }

private:
    virtual void Connect(Client client, ConnectRequest connectRequest) = 0;

    virtual void Event(Client client, EventRequest eventRequest) = 0;

    void switcher(int type, Client client, const void *request) {
        switcher((RequestType) type, client, (const google::protobuf::Message *) request);
    }

    void switcher(RequestType type, Client client, const google::protobuf::Message *request) {
        switch (type) {
            case CONNECT:
                Connect(client, *(ConnectRequest *) request);
                break;
            case EVENT:
                Event(client, *(EventRequest *) request);
                break;
        }
    }
};

#endif //SERVER_PROTOCOL_H
