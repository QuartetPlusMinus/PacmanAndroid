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

//void steps(std::vector<GameRoom* >& rooms) {
//    while( 1 ) {
//        for( int i = 0; i < rooms.size(); ++i) {
//            std::cout << "Hello" << std::endl;
//        }
//    }
//}

class Game : public Service {
public:
    Game(unsigned short port) : Service(port) {
    }

    void start() {
//        std::thread gameStepsMaker(steps, std::ref(rooms));
//        gameStepsMaker.detach();
//        run();
        boost::thread thread([this]() { this->run(); });
//        thread.detach();
        thread.join();
        std::cout << "Я дошел до этой точки!" << std::endl;
    }
    std::vector<GameRoom *> rooms;

private:

    virtual void Connect(Client *client, Messages::ConnectMessage &connectMsg) final {
        client->setUsername(connectMsg.name());

        clients.push(client); // Добавить пользователя в очередь
        std::cout << "Client connected to server. Username: " << connectMsg.name() << endl;

        if (clients.size() >= clientsInRoom) { // Если набралось нужное кол-во пользователей

            // Создаём комнату
            // TODO: Так нельзя делать !!!!!!
            // Добавить 20 постоянных комнат и менеджер для них

            GameRoom *room = new GameRoom(new GameMap::Default());

            rooms.push_back(room);

            for (unsigned int i = 0; i < clientsInRoom; i++) {
                Client *currentClient = clients.front();
                clients.pop();
                room->addClient(currentClient);
                // Добавление в таблицу клиент - комната
                clientInRoom[currentClient->hash()] = room;
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
        if (clientInRoom.find(client->hash()) != clientInRoom.end()){
            std::cout << "Client send event to server\n";
            GameRoom* room = clientInRoom[client->hash()];
            room->printPlayers();
        }
    }

    const int clientsInRoom = 2;
    const int ghostsInRoom = 5;

    std::queue<Client *> clients;
    std::unordered_map<unsigned int, GameRoom *> clientInRoom;

};

#endif //SERVER_GAME_H
