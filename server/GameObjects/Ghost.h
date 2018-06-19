//
// Created by murt on 13.06.18.
//

#ifndef SERVER_GHOST_H
#define SERVER_GHOST_H


#include "../../common/Serialization/Samples.h"
#include "Pacman.h"

class Ghost : public Samples::Unit {
public:
    Ghost() : target(nullptr) {}

    Pacman* target;
    void step() {
        if( this->entrypercent() >= 1.0f) {
            this->mutable_pos()->set_x((sz::uint8)(this->pos().x() + 1));
            this->set_entrypercent(0.0f);
        }
        this->set_direction(Samples::RIGHT);
        this->set_entrypercent(this->entrypercent() + 0.25f);
    }

};


#endif //SERVER_GHOST_H
