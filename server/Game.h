//
// Created by views on 13.05.18.
//

#ifndef SERVER_GAME_H
#define SERVER_GAME_H

#include <iostream>
#include <memory>
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
        // инициализация карт
        std::shared_ptr<GameMap::Map> gameMap(new GameMap::Default());
        maps.push_back(gameMap); // пока только одна карта`
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

    std::vector<std::shared_ptr<GameRoom>> rooms;

private:

    virtual void Connect(Client *client, Messages::ConnectMessage &connectMsg) final {
        client->setUsername(connectMsg.name());

        clients.push(client); // Добавить пользователя в очередь
        std::cout << "Client connected to server. Username: " << connectMsg.name() << endl;

        if (clients.size() >= clientsCountInRoom) { // Если набралось нужное кол-во пользователей

            // Создаём комнату
            // TODO: Так нельзя делать !!!!!!
            // Добавить 20 постоянных комнат и менеджер для них
            std::shared_ptr<GameRoom> room(new GameRoom(getMap().get()));
            rooms.push_back(room);

            for (unsigned int i = 0; i < clientsCountInRoom; i++) {
                Client *currentClient = clients.front();
                clients.pop();
                room->addClient(currentClient);
                // Добавление в таблицу клиент - комната
                clientInRoom[currentClient->hash()] = room;
            }

            try {
                room->start();
            } catch (PlayerCountException *e) {
                cout << e->what();
            }


        } else {

            // Если комната не набралась, то отсылаем статус в очереди
            Messages::QueueMessage queueReply;
            queueReply.set_position((Messages::SimpleTypes::uint16) clients.size());
            client->Queue(queueReply);
            usleep(2000);
        }
    }

    virtual void Event(Client *client, Messages::EventMessage &eventMsg) final {
        if (clientInRoom.find(client->hash()) != clientInRoom.end()) {
            std::cout << "Client send event to server\n";
            clientInRoom[client->hash()]->printPlayers();
        }
    }

    std::shared_ptr<GameMap::Map> getMap() const {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(0, maps.size() - 1);
        int index = dist(mt);
        return maps[index];


    }

    const int clientsCountInRoom = 2;
    const int ghostsInRoom = 5;

    std::queue<Client *> clients;
    std::unordered_map<unsigned int, std::shared_ptr<GameRoom>> clientInRoom;
    std::vector<std::shared_ptr<GameMap::Map>> maps;

};

#endif //SERVER_GAME_H
