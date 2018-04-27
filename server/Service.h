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

class Service : public Network {
public:
    Service(unsigned short port):
            Network(port) {
    }

    // ----------------------------------------------------------------------------------------------------------------

private:
    void Connect(Client client, ConnectRequest connectRequest) {
        // your code

        QueueReply queueReply;

        client.Queue(queueReply);

        // Код Ильнура должен быть тут
    }

    void Event(Client client, EventRequest eventRequest) {
        // your code

        // Код Ильнура должен быть тут
    }

    std::queue clients; // ???
};

#endif //SERVER_PROTOCOL_H
