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

    // Количество приведений в комнате
    int ghostsInRoom = 5;

private:

    virtual void Connect(Client client, ConnectRequest &connectRequest) final {
        client.setUsername(connectRequest.name());

        clients.push(client);
        std::cout << "Client connected to server. Username: " << connectRequest.name() << endl;

        // Если набралась комната
        if (long(clients.size()) >= long(clientsInRoom)) {

            // Создаём комнату
            GameRoom *room = new GameRoom(clientsInRoom, ghostsInRoom);
            rooms.push_back(room);

            // Отсылаем каждому запрос о начале игры
            for (int i = 0; i < clientsInRoom; i++) {

                Client currentClient = clients.front();

                StartReply startReply;
                startReply.set_id(i);

                // Генерируем юнит пакмена
                room->appendUser(client, startReply.add_unit());

                // Генерируем юниты приведений
                for (int j = 0; j < ghostsInRoom; j++) {
                    room->appendGhost(j, startReply.add_unit());
                }

                // Добавляем карту
//                for (int j = 0; j < room->getMap()->data.size(); j++) {
//                    startReply.add_map(room->getMap()->data[j]);
//                }

                currentClient.Start(startReply);

                clients.pop();
            }

        } else {

            // Если комната не набралась, то отсылаем статус в очереди
            QueueReply queueReply;
            queueReply.set_position(int(clients.size()));
            client.Queue(queueReply);
<<<<<<< HEAD
            usleep(200000);
=======
>>>>>>> origin/server
        }
    }

    virtual void Event(Client client, EventRequest &eventRequest) final {
        std::cout << "Client send event to server\n";
    }

    std::queue<Client> clients;
    std::vector<GameRoom *> rooms;
};

#endif //SERVER_GAME_H
