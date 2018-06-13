//
// Created by murt on 11.06.18.
//

#include <random>
#include "../lib/GameRoomsManager.h"

GameRoomsManager::GameRoomsManager(unsigned int countOfRooms): countOfRooms(countOfRooms)
{
    // инициализация карт
    GameMap::Map* gameMap = new GameMap::Default();
    maps.push_back(gameMap); // пока только одна карта
}

bool GameRoomsManager::CanAddRoom() {
    if( gameRooms.size() < countOfRooms) {
        return true;
    }
    return false;
}

GameRoom* GameRoomsManager::AddRoom() {
    if( !CanAddRoom()) {
        return nullptr;
    }
    GameRoom* newGameRoom = new GameRoom(getMap());
    gameRooms.push_back(newGameRoom);
    return newGameRoom;
}

GameMap::Map* GameRoomsManager::getMap() const {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, maps.size() - 1);
    int index = dist(mt);
    return maps[index];
}