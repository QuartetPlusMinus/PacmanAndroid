//
// Created by views on 27.05.18.
//

#ifndef SERVER_GAMEMAPDEFAULT_H
#define SERVER_GAMEMAPDEFAULT_H

#include "GameMap.h"

static const unsigned int PLAYERS_COUNT = 2;
static const unsigned int GHOSTS_COUNT = 5;
const std::string data[] = {"===============",   // 1
                            "==   ==========",   // 2
                            "== = ==    ====",   // 3
                            "== =    == ====",   // 4
                            "== ======= ====",   // 5
                            "==      == ====",   // 6
                            "== ====     ===",   // 7
                            "== ==== =======",   // 8
                            "== =    =======",   // 9
                            "==      =======",   // 10
                            "== ==== =======",   // 11
                            "== ==== =======",   // 12
                            "=  ==== =======",   // 13
                            "= ===== =======",   // 14
                            "= ===== =======",   // 15
                            "= ===== =======",   // 16
                            "= ===== =======",   // 17
                            "= ===== =======",   // 18
                            "= ===== =======",   // 19
                            "= ===== =======",   // 20
                            "= ===== =======",   // 21
                            "=  ==== =======",   // 22
                            "==      =======",   // 23
                            "==============="};

namespace GameMap {
    class Default : public Map {
    public:
        Default() : Map(PLAYERS_COUNT, GHOSTS_COUNT) {

            playersPositions.reserve(PLAYERS_COUNT);
            ghostsPositions.reserve(GHOSTS_COUNT);


            playersPositions[0].set_x(0);
            playersPositions[0].set_y(0);

            playersPositions[1].set_x(1);
            playersPositions[1].set_y(0);

            ghostsPositions[0].set_x(0);
            ghostsPositions[0].set_y(1);

            ghostsPositions[1].set_x(1);
            ghostsPositions[1].set_y(1);

            ghostsPositions[2].set_x(2);
            ghostsPositions[2].set_y(1);

            ghostsPositions[3].set_x(3);
            ghostsPositions[3].set_y(1);

            ghostsPositions[4].set_x(4);
            ghostsPositions[4].set_y(1);
        }

        virtual const std::string *getTileMap() final {
            return data;
        }

    };
}
// 24

#endif //SERVER_GAMEMAPDEFAULT_H
