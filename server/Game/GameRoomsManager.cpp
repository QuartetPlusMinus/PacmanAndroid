//
// Created by murt on 11.06.18.
//

#include "GameRoomsManager.h"

void gameStep(std::list<std::shared_ptr<GameRoom>> &gameRooms) {
//    std::cout << "STEPPER" << std::endl;
    std::chrono::milliseconds period{GameTimer::PERIOD};

    // TODO: handle Ctrl+C
    while (true) {
        for (auto room: gameRooms) {
            if (room->ready && room->started && !room->gameOver) {

                room->step();
            } else if (!room->started && room->ready) {
                room->start();
            }
        }
    }
}


GameRoomsManager::GameRoomsManager(unsigned int countOfRooms) : countOfRooms(countOfRooms) {
    std::thread gameStepper(gameStep, std::ref(gameRooms));
    gameStepper.detach();
}


void GameRoomsManager::cleanRooms() {
    gameRooms.remove_if([](std::shared_ptr<GameRoom> room) { return !room->gameOver; });
}

bool GameRoomsManager::CanAddRoom() {
    cleanRooms();
    return gameRooms.size() < countOfRooms;
}

std::shared_ptr<GameRoom> GameRoomsManager::AddRoom(const TileMap *map) {
    if (!CanAddRoom()) {
        return nullptr;
    }

    std::shared_ptr<GameRoom> newGameRoom = std::make_shared<GameRoom>(map);
    gameRooms.push_back(newGameRoom);
    return newGameRoom;
}