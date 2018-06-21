//
// Created by murt on 13.06.18.
//

#ifndef SERVER_GHOST_H
#define SERVER_GHOST_H


#include "../../common/Serialization/Samples.h"
#include "Pacman.h"
#include "../Graph/SetGraph.h"
#include "../../common/Constants/ConstValues.h"

class Ghost : public Samples::Unit {
public:

    Ghost(std::vector<std::shared_ptr<Pacman>> &pacmans);
    void choiceDirection(SetGraph &gameMap);
    void step(SetGraph &gameMap);
    void setRoundPosition();

    RoundPosition rPos;
    std::shared_ptr<Pacman> target;
};


#endif //SERVER_GHOST_H
