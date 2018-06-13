//
// Created by viewsharp on 27.04.18.
//

#ifndef SERVER_GAMEROOM_H
#define SERVER_GAMEROOM_H

#include "Service.h"
#include "GameMap.h"
#include "Player.h"

class PlayerCountException : public std::runtime_error {
public:
    explicit PlayerCountException(const std::string &what_arg) : std::runtime_error(what_arg) {}
};

class GameRoom {

public:

    explicit GameRoom(GameMap::Map *map);

    void addClient(Client *client);

    void start();

private:

    std::vector<Player *> players;
    std::vector<Messages::Unit *> ghosts;

    const GameMap::Map *map;

};

#endif //SERVER_GAMEROOM_H
