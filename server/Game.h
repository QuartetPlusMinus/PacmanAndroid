//
// Created by views on 13.05.18.
//

#ifndef SERVER_GAME_H
#define SERVER_GAME_H

#include <iostream>
#include "Service.h"
#include "GameRoom.h"
#include "Player.h"
#include "GameMapDefault.h"

class Game : public Service {
public:
    Game(unsigned short port) : Service(port) {
    }

    void start() {
        boost::thread thread([this]() { this->run(); });
        thread.join();
    }


private:

    virtual void Connect(Client *client, Messages::ConnectMessage &connectMsg) final {
        client->setUsername(connectMsg.name());

        clients.push(client); // Добавить пользователя в очередь
        std::cout << "Client connected to server. Username: " << connectMsg.name() << endl;

        if (clients.size() >= clientsInRoom) { // Если набралось нужное кол-во пользователей

            // Создаём комнату
            // TODO: Так нельзя делать !!!!!!
            GameRoom *room = new GameRoom(new GameMap::Default());

            rooms.push_back(room);

            // Отсылаем каждому запрос о начале игры
            for (unsigned int i = 0; i < clientsInRoom; i++) {
                Client *currentClient = clients.front();
                clients.pop();
                room->addClient(currentClient);
            }

            try {
                room->start();
            } catch (PlayerCountException *e) {
                cout<<e->what();
            }


        } else {

            // Если комната не набралась, то отсылаем статус в очереди
            Messages::QueueMessage queueReply;
            queueReply.set_position((Messages::SimpleTypes::uint16)clients.size());
            client->Queue(queueReply);
            usleep(2000);
        }
    }

    virtual void Event(Client *client, Messages::EventMessage &eventMsg) final {
            std::cout << "Client send event to server\n";
    }

    const int clientsInRoom = 2;
    const int ghostsInRoom = 5;

    std::queue<Client *> clients;
    std::vector<GameRoom *> rooms;
};

#endif //SERVER_GAME_H
