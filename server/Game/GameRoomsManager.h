//
// Created by murt on 11.06.18.
//

#ifndef SERVER_GAMEROOMSMANAGER_H
#define SERVER_GAMEROOMSMANAGER_H

#include <random>

#include "GameRoom.h"
#include "MapManager.h"

class GameRoomsManager {
public:
    GameRoomsManager(unsigned int countOfRooms);

    ~GameRoomsManager();

    bool CanAddRoom();

    GameRoom *AddRoom();

    void cleanRooms();

private:
    std::list<GameRoom *> gameRooms;
    unsigned int countOfRooms;

};


#endif //SERVER_GAMEROOMSMANAGER_H
