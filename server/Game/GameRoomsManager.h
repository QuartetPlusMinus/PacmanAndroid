//
// Created by murt on 11.06.18.
//

#ifndef SERVER_GAMEROOMSMANAGER_H
#define SERVER_GAMEROOMSMANAGER_H

#include <random>

#include "GameRoom.h"
#include "MapManager.h"
#include <chrono>

class GameRoomsManager {
public:
    explicit GameRoomsManager(unsigned int countOfRooms);

    ~GameRoomsManager();

    bool CanAddRoom();

    GameRoom *AddRoom(const TileMap *map); // TODO: make  smart ptr

    void cleanRooms();

private:
    std::list<GameRoom *> gameRooms; // TODO: make smart ptr
    unsigned int countOfRooms;

};


#endif //SERVER_GAMEROOMSMANAGER_H
