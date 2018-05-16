//
// Created by views on 13.05.18.
//

#ifndef SERVER_GAME_H
#define SERVER_GAME_H

#include "Service.h"
#include "GameRoom.h"

class Game : public Service {
public:
    Game(unsigned short port) : Service(port) {
    }

    void start() {
        boost::thread thread([this]() { this->run(); });
        thread.join();
    }

    // Количество игроков в комнате
    int clientsInRoom = 2;

private:

    virtual void Connect(Client client, ConnectRequest &connectRequest) final {
        client.setUsername(connectRequest.name());

        clients.push(client);
        std::cout << "Client connected to server. Username: " << connectRequest.name() << endl;

        // Если набралась комната
        if (long(clients.size()) >= long(clientsInRoom)) {

            // Отслыаем каждому запрос о начале игры
            for (int i = 0; i < clientsInRoom; i++) {

                Client currentClient = clients.front();

                StartReply startReply;

                startReply.set_id(i);

                UnitInit *unit = startReply.add_unit();
                unit->set_type(PACMAN);
                unit->set_name(client.username);
                //unit->set_data(GameRoom.defaultUnit(i));

                currentClient.Start(startReply);

                clients.pop();
            }

        } else {

            // Если комната не набралась, то отсылаем статус в очереди
            QueueReply queueReply;
            queueReply.set_position(int(clients.size()));
            client.Queue(queueReply);
        }
    }

    virtual void Event(Client client, EventRequest &eventRequest) final {
        std::cout << "Client send event to server\n";
    }

    std::queue<Client> clients;

};

#endif //SERVER_GAME_H
