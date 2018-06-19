//
// Created by viewsharp on 27.04.18.
//

#ifndef SERVER_GAMEROOM_H
#define SERVER_GAMEROOM_H

#include "../../NetWork/lib/Service.h"
#include "GameMap.h"
#include "../../GameObjects/lib/Pacman.h"
#include "../../GameObjects/lib/Ghost.h"
#include "GameMapDefault.h"

class PlayerCountException : public std::runtime_error {
public:
    explicit PlayerCountException(const std::string &what_arg) : std::runtime_error(what_arg) {}
};


class GameRoom {

public:
//    GameRoom();

    explicit GameRoom(GameMap::Map *map);

    void addClient(Client *client);

    void start();

    void connect(Client *client);

    void step();

    void eventStep(Messages::Direction direction);


    std::atomic<bool> ready;
    std::atomic<bool> gameOver;
    std::chrono::time_point<std::chrono::steady_clock> lastStepTime;
    std::chrono::milliseconds period{GameTimer::PERIOD};
private:

    std::vector<Pacman *> players;
    std::vector<Ghost *> ghosts;
    const GameMap::Map *map;


};

#endif //SERVER_GAMEROOM_H
