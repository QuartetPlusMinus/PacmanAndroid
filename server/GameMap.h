//
// Created by Artem Belkov on 17/05/2018.
//

#ifndef SERVER_GAMEMAP_H
#define SERVER_GAMEMAP_H

#include <string>
#include <service.pb.h>

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

        std::vector<threedouble::proto::Point> playersPositions;
        std::vector<threedouble::proto::Point> ghostsPositions;
    };
};


#endif //SERVER_GAMEMAP_H
