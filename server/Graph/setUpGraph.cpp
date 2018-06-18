#include <iostream>

#include "setUpGraph.h"

enum Direction {
    NONE = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3,
    UP = 4,
};


void setUp(VirtGraph *gameMap, std::string *stringMap, unsigned int width, unsigned int height) {

//    for (int i = 0; i < height * width; ++i) {
//
//        if (stringMap[i] == 1) {
//            int neighbor = i - WIDTH;
//            if (stringMap[neighbor] == 1) {
//                gameMap.AddEdge(i, neighbor);
//            }
//            neighbor = i + 1;
//            if (stringMap[neighbor] == 1) {
//                gameMap.AddEdge(i, neighbor);
//            }
//            neighbor = i - 1;
//            if (stringMap[neighbor] == 1) {
//                gameMap.AddEdge(i, neighbor);
//            }
//            neighbor = i + WIDTH;
//            if (stringMap[neighbor] == 1) {
//                gameMap.AddEdge(i, neighbor);
//            }
//        }
//    }

    for (int i = 1; i < height - 1; ++i) {
        for (int j = 1; j < width - 1; ++j) {
            if (stringMap[i][j] == ' ') {
                if (stringMap[i][j + 1] == 1) { // Есть путь спрва
                    gameMap->AddEdge(i * height + j, i * height + j + 1);
                }
                if (stringMap[i][j - 1] == 1) {
                    gameMap->AddEdge(i * height + j, i * height + j - 1);
                }
                if (stringMap[i - 1][j] == 1) {
                    gameMap->AddEdge(i * height + j, (i - 1) * height + j);
                }
                if (stringMap[i + 1][j] == 1) {
                    gameMap->AddEdge(i * height + j, (i + 1) * height + j);
                }
            }
        }
    }

}

void find() {
    int start = 6;
    int goal = 13;
    std::queue<int> frontier;
    frontier.push(start);
    std::unordered_set<int> visited;
    visited.insert(start);

    while (frontier.size() > 0) {
        int curent = frontier.front();
        frontier.pop();

//        for (auto next: gameMap->GetNextVertices(curent)) {
////            std::unordered_set<int>::const_iterator vertex = visited.find(next);
//            if (visited.count(next) == 0) {
//                if (next == goal) {
//                    Direction dir = NONE;
//                    int difference = next - curent;
//                    switch (difference) {
//                        case 1:
//                            dir = RIGHT;
//                            break;
//                        case -1:
//                            dir = LEFT;
//                            break;
//                        case WIDTH:
//                            dir = DOWN;
//                            break;
//                        case -WIDTH:
//                            dir = UP;
//                            break;
//                        default:
//                            dir = NONE;
//                            break;
//                    }
//                    std::cout << "DIRECTION: " << dir << std::endl;
//                    break;
//                }
//                std::cout << next << ") " << next / WIDTH << " : " << next % WIDTH << std::endl;
//                frontier.push(next);
//                visited.insert(next);
//            }
//        }
    }
}