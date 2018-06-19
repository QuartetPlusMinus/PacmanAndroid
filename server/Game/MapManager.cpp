//
// Created by views on 19.06.18.
//

#include "MapManager.h"

//TODO: убрать хардкод
static const std::string MAPS_PATH = "/home/views/github/PacmanAndroid/server/src/maps/";

#ifdef _WIN32

#include <windows.h>

void read_directory(const std::string& name, std::vector<std::string>& v)
{
    std::string pattern(name);
    pattern.append("\\*");
    WIN32_FIND_DATA data;
    HANDLE hFind;
    if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
        do {
            v.push_back(data.cFileName);
        } while (FindNextFile(hFind, &data) != 0);
        FindClose(hFind);
    }
}

#else

#include <sys/types.h>
#include <dirent.h>

void read_directory(const std::string& name, std::vector<std::string>& v)
{
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != nullptr) {
        v.emplace_back(dp->d_name);
    }
    closedir(dirp);
}

#endif

MapManager *MapManager::_self = nullptr;

MapManager::MapManager() {
    std::vector<std::string> mapsNames;

    read_directory(MAPS_PATH, mapsNames);

    for (auto &mapName: mapsNames) {

        if (mapName == "." || mapName == "..")
            continue;

        TileMap tileMap;
        std::ifstream in(MAPS_PATH + mapName, std::ios::binary);

        in.seekg(0, std::ios::end);
        size_t size = in.tellg();
        std::string buffer(size, ' ');
        in.seekg(0);
        in.read(&buffer[0], size);

        tileMap.parseFromString(buffer);
        maps.emplace_back(tileMap);
    }
}

const TileMap &MapManager::getRandomMap() const {
    std::random_device random_device;
    std::mt19937 engine{random_device()};
    std::uniform_int_distribution<int> dist(0, (int)maps.size() - 1);
    return maps[dist(engine)];
}

const TileMap &MapManager::getMap(int index) const {
    assert(index < maps.size());
    return maps[index];
}

MapManager *MapManager::Instance() {
    if (!_self) {
        _self = new MapManager();
    }
    return _self;
}

bool MapManager::DeleteInstance() {
    if (_self) {
        delete _self;
        _self = nullptr;
        return true;
    }
    return false;
}