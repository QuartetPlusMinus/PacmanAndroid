//
// Created by views on 26.05.18.
//

#ifndef SERVER_PLAYER_H
#define SERVER_PLAYER_H

#include <service.pb.h>
#include "Client.h"

using namespace threedouble::proto;

class Player : public Unit {
public:
    explicit Player(Client *client) :
            client(client) {

    }

    const Client *client;
};

#endif //SERVER_PLAYER_H
