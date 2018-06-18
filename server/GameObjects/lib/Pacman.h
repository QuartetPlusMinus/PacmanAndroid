//
// Created by views on 26.05.18.
//

#ifndef SERVER_PLAYER_H
#define SERVER_PLAYER_H

#include "../../NetWork/lib/Client.h"


class Pacman : public Messages::Unit {
public:
    explicit Pacman(Client *client) :
            client(client) {

    }

    const Client *client;

    void step() {
        this->mutable_pos()->set_x(this->pos().x() + 1);
        this->set_direction(Messages::Direction::RIGHT);
    }
};

#endif //SERVER_PLAYER_H
