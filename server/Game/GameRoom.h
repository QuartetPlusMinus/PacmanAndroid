//
// Created by viewsharp on 27.04.18.
//

#ifndef SERVER_GAMEROOM_H
#define SERVER_GAMEROOM_H

#include <chrono>
#include "../NetWork/Service.h"
#include "../GameObjects/Pacman.h"
#include "../GameObjects/Ghost.h"
#include "../../common/Serialization/TileMap.h"
#include "../../common/Constants/ConstValues.h"
#include "../Graph/SetGraph.h"

class PlayerCountException : public std::runtime_error {
public:
    explicit PlayerCountException(const std::string &what_arg) : std::runtime_error(what_arg) {}
};

class GameRoom {
public:

    explicit GameRoom(const TileMap *map);

    void addClient(std::shared_ptr<Client> client);

    void start();

    void connect(Client *client);

    void step();

    void checkGhostPacmanCollision();

    std::shared_ptr<Pacman> getPacman(const std::shared_ptr<Client> client) const;


    std::atomic<bool> ready;
    std::atomic<bool> gameOver;
    std::atomic<bool> started;
    std::chrono::time_point<std::chrono::steady_clock> lastStepTime;
    std::chrono::milliseconds period{GameTimer::PERIOD};

    SetGraph gameGraph{GameMap::HEIGHT * GameMap::WIDTH};
private:

    std::vector<std::shared_ptr<Pacman>> players;
    std::vector<std::shared_ptr<Ghost>> ghosts;
    const TileMap *map;
    int killedPacmans;
};

#endif //SERVER_GAMEROOM_H
