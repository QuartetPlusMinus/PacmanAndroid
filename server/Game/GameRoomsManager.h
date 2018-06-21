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

    ~GameRoomsManager()= default;

    bool CanAddRoom();

    std::shared_ptr<GameRoom> AddRoom(const TileMap *map);

    void cleanRooms();

private:
    std::list<std::shared_ptr<GameRoom>> gameRooms;
    unsigned int countOfRooms;

};


#endif //SERVER_GAMEROOMSMANAGER_H
