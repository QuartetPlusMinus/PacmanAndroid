//
// Created by viewsharp on 27.04.18.
//

#ifndef SERVER_GAMEROOM_H
#define SERVER_GAMEROOM_H

#include "Service.h"

class GameRoom {

public:

    GameRoom(int count) {
        unitsCount = count;
    }

    void appendClient(Client client, UnitInit *unitInit) {

        unitInit->set_type(PACMAN);
        unitInit->set_name(client.username);

        Unit *unit = unitInit->mutable_data();

        calculateStartPosition(unitInits.size(), unit->mutable_pos());

        unit->set_direction(UP);
        unit->set_entrypercent(0);
        unit->set_status(ALIVE);
        unit->set_health(3); // max lives count

        std::cout << "Add unit to room" << endl;

        unitInits.push_back(unitInit);
    }

private:

    void calculateStartPosition(int index, Point *point) {

        point->set_x(0);
        point->set_y(0);
    }

    int unitsCount = 0;
    std::vector<UnitInit *> unitInits;
};

#endif //SERVER_GAMEROOM_H
