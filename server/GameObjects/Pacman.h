//
// Created by views on 26.05.18.
//

#ifndef SERVER_PLAYER_H
#define SERVER_PLAYER_H

#include "../NetWork/Client.h"


class Pacman : public Samples::Unit {
public:
    explicit Pacman(Client *client) :
            client(client) {

    }

    const Client *client;

    void step() {
        this->mutable_pos()->set_x(this->pos().x() + 1);
        this->set_direction(Samples::RIGHT);
    }
};

#endif //SERVER_PLAYER_H
