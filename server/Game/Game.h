//
// Created by views on 13.05.18.
//

#ifndef SERVER_GAME_H
#define SERVER_GAME_H

#include <iostream>
#include <memory>

#include "GameRoom.h"
#include "../GameObjects/Pacman.h"
#include "GameRoomsManager.h"
#include "../NetWork/Service.h"


class Game : public Service {
public:
    explicit Game(unsigned short port);
    void start();

    std::vector<std::shared_ptr<GameRoom>> rooms;
    std::atomic_bool canAddGameRooms;

private:

    virtual void Connect(std::shared_ptr<Client> client, Messages::ConnectMessage &connectMsg) final; // TODO: Small first letter
    virtual void Event(std::shared_ptr<Client> client, Messages::EventMessage &eventMsg) final; // TODO: Small first letter


    const unsigned int gameRoomsCount = 10; // TODO: upcase

    std::queue<Client *> clients;
    std::vector<std::shared_ptr<Client>> clientsQueue;
    std::unordered_map<unsigned int, GameRoom*> clientInRoom;
    GameRoomsManager manager{gameRoomsCount};

    const TileMap *currentMap; // TODO: make shared ptr
    MapManager *mapManager;
};

#endif //SERVER_GAME_H
