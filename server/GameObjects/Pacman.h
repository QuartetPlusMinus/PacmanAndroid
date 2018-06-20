//
// Created by views on 26.05.18.
//

#ifndef SERVER_PLAYER_H
#define SERVER_PLAYER_H

#include "../NetWork/Client.h"
#include "../Graph/SetGraph.h"
#include "../../common/Constants/ConstValues.h"


class Pacman : public Samples::Unit {
public:
    explicit Pacman(Client *client);
    Samples::Direction newDirection;
    bool haveCollision(SetGraph &gameMap, Samples::Direction direction);
    void step(SetGraph &gameMap);


    const Client *client;
};

#endif //SERVER_PLAYER_H
