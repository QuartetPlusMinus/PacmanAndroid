//
// Created by Artem Belkov on 17/05/2018.
//

#ifndef SERVER_GAMEMAP_H
#define SERVER_GAMEMAP_H

#include <string>
#include <vector>
#include "../../../common/Messages/Messages.h"
#include "../../Graph/SetGraph.h"
#include "../../../common/Constants/ConstValues.h"

//using namespace threedouble::proto;

namespace GameMap {
    class Map {

    public:
        Map(unsigned int playersCount, unsigned int ghostsCount) :
                playersCount(playersCount),
                ghostsCount(ghostsCount) {
        }

        virtual ~Map() = default;

        const unsigned int playersCount;
        const unsigned int ghostsCount;
        const unsigned int width = GameConstants::MAP_WIDTH;
        const unsigned int height = GameConstants::MAP_HEIGHT;

        virtual const std::string *getTileMap() = 0;
        void setUpGraph(std::string* stringMap );



        std::vector<Messages::Point> playersPositions;
        std::vector<Messages::Point> ghostsPositions;
        SetGraph gameMap{width * height};
    };

};


#endif //SERVER_GAMEMAP_H
