//
// Created by Artem Belkov on 17/05/2018.
//

#include "../lib/GameMap.h"


void GameMap::Map::setUpGraph(std::string *stringMap){
    for (int i = 1; i < height - 1; ++i) {
        for (int j = 1; j < width - 1; ++j) {
            if (stringMap[i][j] == ' ') {
                if (stringMap[i][j + 1] == 1) { // Есть путь спрва
                    gameMap.AddEdge(i * height + j, i * height + j + 1);
                }
                if (stringMap[i][j - 1] == 1) {
                    gameMap.AddEdge(i * height + j, i * height + j - 1);
                }
                if (stringMap[i - 1][j] == 1) {
                    gameMap.AddEdge(i * height + j, (i - 1) * height + j);
                }
                if (stringMap[i + 1][j] == 1) {
                    gameMap.AddEdge(i * height + j, (i + 1) * height + j);
                }
            }
        }
    }
}

