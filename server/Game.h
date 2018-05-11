//
// Created by viewsharp on 05.05.18.
//

#ifndef SERVER_GAME_H
#define SERVER_GAME_H

#include "Service.h"

class Game: public Service {
public:
    Game(unsigned short initiatorPort, unsigned short receiverPort) :
            Service(receiverPort),
            initiatorPort(initiatorPort) {
    }

    void loop() {
        boost::thread thread(boost::bind(run));
    }

private:

    void Connect(Client client, ConnectRequest connectRequest) final{
        clients.push(client);
        std::cout << "Client connected to server\n";
    }

    void Event(Client client, EventRequest eventRequest) final{
        std::cout << "Client send event to server\n";
    }

    const unsigned short initiatorPort;
    std::queue<Client> clients;
};

#endif //SERVER_GAME_H
