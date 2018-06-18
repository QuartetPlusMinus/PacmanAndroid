//
// Created by murt on 11.06.18.
//

#ifndef SERVER_GAMEROOMSMANAGER_H
#define SERVER_GAMEROOMSMANAGER_H

#include "GameRoom.h"

class GameRoomsManager {
public:
    GameRoomsManager(unsigned int countOfRooms);
    ~GameRoomsManager();
    bool CanAddRoom();
    GameRoom* AddRoom();
    void cleanRooms();

private:
    GameMap::Map* getMap() const;

    std::list<GameRoom*> gameRooms;
    unsigned int countOfRooms;
    std::vector<GameMap::Map*> maps;

};


#endif //SERVER_GAMEROOMSMANAGER_H
