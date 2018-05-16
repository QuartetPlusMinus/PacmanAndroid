//
// Created by viewsharp on 27.04.18.
//

#ifndef SERVER_GAMEROOM_H
#define SERVER_GAMEROOM_H

#include "Service.h"
#include "GameMap.h"

class GameRoom {

public:

    GameRoom(int usersCount, int ghostsCount) {
        usersUnitsCount = usersCount;
        ghostsUnitsCount = ghostsCount;
    }

    void appendUser(Client client, UnitInit *unitInit) {

        unitInit->set_type(PACMAN);
        unitInit->set_name(client.username);

        Unit *unit = unitInit->mutable_data();

        calculateUserStartPosition(usersUnits.size(), unit->mutable_pos());

        unit->set_direction(UP);
        unit->set_entrypercent(0);
        unit->set_status(ALIVE);
        unit->set_health(3); // max lives count

        std::cout << "Add user to room" << endl;

        usersUnits.push_back(unitInit);
    }

    void appendGhost(int index, UnitInit *unitInit) {

        unitInit->set_type(GHOST);
        unitInit->set_name("GHOST");

        Unit *unit = unitInit->mutable_data();

        // Если юнит приведения уже есть
        if (ghostsUnits.size() > index) {

            Unit savedUnit = ghostsUnits[index]->data();

            unit->set_allocated_pos(savedUnit.mutable_pos());

            unit->set_direction(savedUnit.direction());
            unit->set_entrypercent(savedUnit.entrypercent());

            std::cout << "Update ghost in room" << endl;

        } else {

            calculateGhostStartPosition(usersUnits.size(), unit->mutable_pos());

            unit->set_direction(UP);
            unit->set_entrypercent(0);

            std::cout << "Add ghost to room" << endl;

            usersUnits.push_back(unitInit);
        }
    }

//    GameMap * getMap() {
//        return map;
//    }

private:

    void calculateUserStartPosition(int index, Point *point) {

        //TODO: Рассчитать начальную позицию пакмена

        point->set_x(0);
        point->set_y(0);
    }

    void calculateGhostStartPosition(int index, Point *point) {

        //TODO: Рассчитать начальную позицию приведения

        point->set_x(0);
        point->set_y(0);
    }

    int usersUnitsCount = 0;
    std::vector<UnitInit *> usersUnits;

    int ghostsUnitsCount = 0;
    std::vector<UnitInit *> ghostsUnits;

//    GameMap *map = new GameMap();
};

#endif //SERVER_GAMEROOM_H
