//
// Created by murt on 13.06.18.
//

#ifndef SERVER_GHOST_H
#define SERVER_GHOST_H


#include "../../../common/Messages/Messages.h"
#include "Pacman.h"

class Ghost : public Messages::Unit {
public:
    Ghost(){

    }

    Pacman* target;
    void step() {
        this->mutable_pos()->set_x(this->pos().x() + 1);
        this->set_direction(Messages::Direction::RIGHT);
    }

};


#endif //SERVER_GHOST_H
