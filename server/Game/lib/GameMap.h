//
// Created by Artem Belkov on 17/05/2018.
//

#ifndef SERVER_GAMEMAP_H
#define SERVER_GAMEMAP_H

#include <string>
#include <vector>
#include "../../../common/Messages/Messages.h"

//using namespace threedouble::proto;

namespace GameMap {
    class Map {

    public:
        Map(unsigned int playersCount, unsigned int ghostsCount) :
                playersCount(playersCount),
                ghostsCount(ghostsCount),
                width(0),
                height(0) {
        }

        const unsigned int playersCount;
        const unsigned int ghostsCount;
        const unsigned int width;
        const unsigned int height;

        virtual const std::string *getTileMap() = 0;

        std::vector<Messages::Point> playersPositions;
        std::vector<Messages::Point> ghostsPositions;
    };
};


#endif //SERVER_GAMEMAP_H
