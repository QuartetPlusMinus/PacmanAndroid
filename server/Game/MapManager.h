//
// Created by views on 19.06.18.
//

#ifndef SERVER_MAPMANAGER_H
#define SERVER_MAPMANAGER_H

#include <random>
#include <vector>
#include <cassert>
#include <fstream>

#include "../../common/Serialization/TileMap.h"

// Singleton template

class MapManager {
protected:
    static MapManager *_self;

    MapManager();

    virtual ~MapManager() = default;

public:
    static MapManager *Instance();

    static bool DeleteInstance();

    const TileMap *getRandomMap() const; // TODO: make shared ptr

    const TileMap *getMap(int index) const; // TODO: make shared ptr

private:
    std::vector<TileMap> maps; // TODO: make shared ptr
};

#endif //SERVER_MAPMANAGER_H
