//
// Created by views on 13.05.18.
//

#ifndef SERVER_GAME_H
#define SERVER_GAME_H

#include <iostream>
#include <memory>

#include "GameRoom.h"
#include "Player.h"
#include "../src/GameMapDefault.h"
#include "../../NetWork/lib/Service.h"


class Game : public Service {
public:
    Game(unsigned short port);

    void start();

    std::vector<std::shared_ptr<GameRoom>> rooms;
    std::atomic_bool canAddGameRooms;

private:

    virtual void Connect(std::shared_ptr<Client> client, Messages::ConnectMessage &connectMsg) final;

    virtual void Event(std::shared_ptr<Client> client, Messages::EventMessage &eventMsg) final;

    std::shared_ptr<GameMap::Map> getMap() const {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(0, maps.size() - 1);
        int index = dist(mt);
        return maps[index];
    }

    const int clientsCountInRoom = 2;
    const int ghostsInRoom = 5;
    const unsigned int gameRoomsCount = 10;

    std::queue<Client *> clients;
    std::vector<std::shared_ptr<Client>> clientsQueue;
    std::unordered_map<unsigned int, std::shared_ptr<GameRoom>> clientInRoom;
    std::vector<std::shared_ptr<GameMap::Map>> maps;
    std::vector<GameRoom> gameRooms{gameRoomsCount};

};

#endif //SERVER_GAME_H
