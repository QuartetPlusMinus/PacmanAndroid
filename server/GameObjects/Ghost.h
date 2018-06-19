//
// Created by murt on 13.06.18.
//

#ifndef SERVER_GHOST_H
#define SERVER_GHOST_H


#include "../../common/Serialization/Samples.h"
#include "Pacman.h"

class Ghost : public Samples::Unit {
public:
    Ghost(){

    }

    Pacman* target;
    void step() {
        this->mutable_pos()->set_x(this->pos().x() + 1);
        this->set_direction(Samples::RIGHT);
    }

};


#endif //SERVER_GHOST_H
