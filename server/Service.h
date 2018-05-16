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

    virtual void switchRequest(int type, ip::udp::endpoint &sender_ep, const char *data, size_t size) final {
        Client client(socket, sender_ep);

        switch ((RequestType)type) {
            case CONNECT: {
                ConnectRequest connectRequest;
                connectRequest.ParseFromArray(data, (int) size);
                Connect(client, connectRequest);
                break;
            }
            case EVENT: {
                EventRequest eventRequest;
                eventRequest.ParseFromArray(data, (int) size);
                Event(client, eventRequest);
                break;
            }
        }
    }

protected:

    virtual void Connect(Client client, ConnectRequest &connectRequest) = 0;

    virtual void Event(Client client, EventRequest &eventRequest) = 0;
};

#endif //SERVER_PROTOCOL_H

