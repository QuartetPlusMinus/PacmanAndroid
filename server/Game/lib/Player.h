//
// Created by views on 26.05.18.
//

#ifndef SERVER_PLAYER_H
#define SERVER_PLAYER_H

#include "../../NetWork/lib/Client.h"


class Player : public Messages::Unit {
public:
    explicit Player(Client *client) :
            client(client) {

    }

    const Client *client;
};

#endif //SERVER_PLAYER_H
