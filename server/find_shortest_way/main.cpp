#include <iostream>

#include <string>
#include <queue>
#include "SetGraph.h"

/*          00000
 *          01010
 *          01110
 *          01010
 *          00000
 */
const int WIDTH = 5;
const int HEIGHT = 5;

enum Direction {
    NONE = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3,
    UP = 4,
};


int main() {
    SetGraph gameMap(WIDTH * HEIGHT);
    bool map[] = {0, 0, 0, 0, 0,
                  0, 1, 0, 1, 0,
                  0, 1, 1, 1, 0,
                  0, 1, 0, 1, 0,
                  0, 0, 0, 0, 0};
    for (int i = 0; i < WIDTH * HEIGHT; ++i) {
        if (map[i] == 1) {
            int neighbor = i - WIDTH;
            if (map[neighbor] == 1) {
                gameMap.AddEdge(i, neighbor);
            }
            neighbor = i + 1;
            if (map[neighbor] == 1) {
                gameMap.AddEdge(i, neighbor);
            }
            neighbor = i - 1;
            if (map[neighbor] == 1) {
                gameMap.AddEdge(i, neighbor);
            }
            neighbor = i + WIDTH;
            if (map[neighbor] == 1) {
                gameMap.AddEdge(i, neighbor);
            }
        }
    }
    int start = 6;
    int goal = 13;
    std::queue<int> frontier;
    frontier.push(start);
    std::unordered_set<int> visited;
    visited.insert(start);

    while (frontier.size() > 0) {
        int curent = frontier.front();
        frontier.pop();

        for (auto next: gameMap.GetNextVertices(curent)) {
//            std::unordered_set<int>::const_iterator vertex = visited.find(next);
            if (visited.count(next) == 0) {
                if( next == goal ) {
                    Direction dir = NONE;
                    int difference = next - curent;
                    switch( difference ){
                        case 1:
                            dir = RIGHT;
                            break;
                        case -1:
                            dir = LEFT;
                            break;
                        case WIDTH:
                            dir = DOWN;
                            break;
                        case -WIDTH:
                            dir = UP;
                            break;
                        default:
                            dir=NONE;
                            break;
                    }
                    std::cout << "DIRECTION: " << dir << std::endl;
                    break;
                }
                std::cout << next << ") "<< next / WIDTH << " : " << next % WIDTH << std::endl;
                frontier.push(next);
                visited.insert(next);
            }
        }
    }

    return 0;
}