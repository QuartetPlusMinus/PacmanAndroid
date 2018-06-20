//
// Created by views on 26.05.18.
//

#ifndef SERVER_PLAYER_H
#define SERVER_PLAYER_H

#include "../NetWork/Client.h"
#include "../Graph/SetGraph.h"
#include "../../common/Constants/ConstValues.h"
#include "GameObject.h"


class Pacman : public Samples::Unit {
public:
    explicit Pacman(Client *client);
    Samples::Direction newDirection;
    bool haveCollision(SetGraph &gameMap, Samples::Direction direction);
    bool step(SetGraph &gameMap);
    void stepToDirection(Samples::Direction direction);
    void setRoundPosition();

    bool injured;
    const Client *client;
    RoundPosition rPos;

};

#endif //SERVER_PLAYER_H
