//
// Created by murt on 11.06.18.
//

#include "GameRoomsManager.h"

void gameStep(std::list<GameRoom *> &gameRooms) {
    std::cout << "STEPPER" << std::endl;
    std::chrono::milliseconds period{GameTimer::PERIOD};
    while (true) {
        GameRoom *firstRoom = nullptr;
        GameRoom *lastRoom = nullptr;
        for (auto room: gameRooms) {
            if (room->ready && room->started && !room->gameOver) {
                if (!firstRoom) {
                    firstRoom = room;
                }
                lastRoom = room;
                room->step();
            } else if (!room->started && room->ready) {
                room->start();
            }
            if (firstRoom && lastRoom) {
                auto sleep_time = std::chrono::duration_cast<std::chrono::milliseconds>(
                        period - (std::chrono::steady_clock::now() - firstRoom->lastStepTime));
                std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
            }
        }
    }
}


GameRoomsManager::GameRoomsManager(unsigned int countOfRooms) : countOfRooms(countOfRooms) {
    std::thread gameStepper(gameStep, std::ref(gameRooms));
    gameStepper.detach();
}

GameRoomsManager::~GameRoomsManager() {
    for (auto room: gameRooms) {
        delete room;
    }
};


void GameRoomsManager::cleanRooms() {

    for (auto room: gameRooms) {
        if (room->gameOver) {
            delete room;
        }
    }
    gameRooms.remove_if([](GameRoom *room) { return !room->gameOver; });
}

bool GameRoomsManager::CanAddRoom() {
    cleanRooms();
    return gameRooms.size() < countOfRooms;
}

GameRoom *GameRoomsManager::AddRoom(const TileMap *map) {
    if (!CanAddRoom()) {
        return nullptr;
    }

    GameRoom *newGameRoom = new GameRoom(map);
    gameRooms.push_back(newGameRoom);
    return newGameRoom;
}