//
// Created by murt on 11.06.18.
//

#include "GameRoomsManager.h"

void gameStep(std::list<GameRoom*>& gameRooms) {
    std::cout << "STEPPER" << std::endl;
    while (true) {
        for (auto room: gameRooms) {
            if( room->ready ){
                room->step();
//                std::cout << "ITERATION" << std::endl;
            }
            usleep(1000000);
        }
    }
}

GameRoomsManager::GameRoomsManager(unsigned int countOfRooms): countOfRooms(countOfRooms)
{
    std::thread gameStepper(gameStep, std::ref(gameRooms));
    gameStepper.detach();
}

GameRoomsManager::~GameRoomsManager(){
    for(auto room: gameRooms) {
        delete room;
    }
};


void GameRoomsManager::cleanRooms() {

    for(auto room: gameRooms) {
        if( room->gameOver ) {
            delete room;
        }
    }
    gameRooms.remove_if([](GameRoom* room){return !room->gameOver;});
}

bool GameRoomsManager::CanAddRoom() {
    cleanRooms();
    if( gameRooms.size() < countOfRooms) {
        return true;
    }
    return false;
}

GameRoom* GameRoomsManager::AddRoom() {
    if( !CanAddRoom()) {
        return nullptr;
    }
    GameRoom* newGameRoom = new GameRoom(MapManager::Instance()->getRandomMap());
    gameRooms.push_back(newGameRoom);
    return newGameRoom;
}