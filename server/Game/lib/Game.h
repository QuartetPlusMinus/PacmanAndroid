//
// Created by views on 13.05.18.
//

#ifndef SERVER_GAME_H
#define SERVER_GAME_H

#include <iostream>
#include <memory>

#include "GameRoom.h"
#include "Player.h"
#include "GameRoomsManager.h"
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



    const int clientsCountInRoom = 2;
    const int ghostsInRoom = 5;
    const unsigned int gameRoomsCount = 10;

    std::queue<Client *> clients;
    std::vector<std::shared_ptr<Client>> clientsQueue;
    std::unordered_map<unsigned int, GameRoom*> clientInRoom;
    GameRoomsManager manager{gameRoomsCount};
};

#endif //SERVER_GAME_H
