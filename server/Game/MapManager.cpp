//
// Created by views on 19.06.18.
//

#include <cstdio>  /* defines FILENAME_MAX */
#include "MapManager.h"

#ifdef _WIN32

#include <windows.h>
#include <direct.h>
#define GetCurrentDir _getcwd

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
#include <unistd.h>
#define GetCurrentDir getcwd

void read_directory(const std::string &name, std::vector <std::string> &v) {
    DIR *dirp = opendir(name.c_str());
    struct dirent *dp;
    while ((dp = readdir(dirp)) != nullptr) {
        v.emplace_back(dp->d_name);
    }
    closedir(dirp);
}

#endif


std::string getCurrentPath() {

    char cCurrentPath[FILENAME_MAX];

    GetCurrentDir(cCurrentPath, sizeof(cCurrentPath));

    cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

//    printf("The current working directory is %s\n", cCurrentPath);
    return std::string(cCurrentPath);
}

MapManager *MapManager::_self = nullptr;

MapManager::MapManager() {
    std::vector <std::string> mapsNames;

    std::string mapsPath = getCurrentPath() + "/src/maps/";

    read_directory(mapsPath, mapsNames);

    for (auto &mapName: mapsNames) {

        if (mapName == "." || mapName == "..")
            continue;

        TileMap tileMap;
        std::ifstream in(mapsPath + mapName, std::ios::binary);

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
    std::uniform_int_distribution<int> dist(0, (int) maps.size() - 1);
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