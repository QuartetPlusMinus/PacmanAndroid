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

    virtual void connect(std::shared_ptr<Client> client, Messages::ConnectMessage &connectMsg) final;
    virtual void event(std::shared_ptr<Client> client, Messages::EventMessage &eventMsg) final;


    const unsigned int GAME_ROOMS_COUNT = 10;

    std::queue<std::shared_ptr<Client>> clients;
//    std::queue<Client *> clients;
    std::vector<std::shared_ptr<Client>> clientsQueue;
    std::unordered_map<unsigned int, std::shared_ptr<GameRoom>> clientInRoom;
    GameRoomsManager manager{GAME_ROOMS_COUNT};

    const TileMap *currentMap;
    MapManager *mapManager;
};

#endif //SERVER_GAME_H
