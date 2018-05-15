//
// Created by views on 13.05.18.
//

#ifndef SERVER_GAME_H
#define SERVER_GAME_H

#include "Service.h"

class Game : public Service {
public:
    Game(unsigned short port) : Service(port) {
    }

    void start() {
        boost::thread thread([this](){this->run(); });
        thread.join();
    }

private:

    virtual void Connect(Client client, ConnectRequest &connectRequest) final {
        clients.push(client);
        std::cout << "Client connected to server. Username: " << connectRequest.name() << endl;
    }

    virtual void Event(Client client, EventRequest &eventRequest) final {
        std::cout << "Client send event to server\n";
    }

    std::queue<Client> clients;

};

#endif //SERVER_GAME_H
