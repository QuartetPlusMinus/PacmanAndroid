//
// Created by murt on 13.06.18.
//

#include <queue>
#include <unordered_set>
#include <random>
#include "Ghost.h"
#include "../../common/Constants/ConstValues.h"


Ghost::Ghost(std::vector<Pacman *> &pacmans) {
    std::random_device random_device;
    std::mt19937 engine{random_device()};
    std::uniform_int_distribution<int> dist(0, (int)pacmans.size() - 1);
    target =  pacmans[dist(engine)];
}

void Ghost::choiceDirection(SetGraph& gameMap) {
    int startVertex = this->pos().x() + GameConstants::MAP_WIDTH * this->pos().y();
    int goalVertex = target->pos().x() + GameConstants::MAP_WIDTH * target->pos().y();
    std::queue<int> frontier;
    frontier.push(startVertex);
    std::unordered_set<int> visited;
    visited.insert(startVertex);

    while (frontier.size() > 0) {
        int curent = frontier.front();
        frontier.pop();

        for (auto next: gameMap.GetNextVertices(curent)) {
            std::unordered_set<int>::const_iterator vertex = visited.find(next);
            if (visited.count(next) == 0) {
                if (next == goalVertex) {
                    Samples::Direction dir = Samples::Direction::NONE;
                    int difference = next - curent;
                    switch (difference) {
                        case 1:
                            dir = Samples::Direction::RIGHT;
                            break;
                        case -1:
                            dir = Samples::Direction::LEFT;
                            break;
                        case GameConstants::MAP_WIDTH:
                            dir = Samples::Direction::DOWN;
                            break;
                        case -GameConstants::MAP_WIDTH:
                            dir = Samples::Direction::UP;
                            break;
                        default:
                            dir = Samples::Direction::NONE;
                            break;
                    }
                    this->set_direction(dir);
//                    std::cout << "DIRECTION: " << dir << std::endl;
                    break;
                }
                frontier.push(next);
                visited.insert(next);
            }
        }
    }
}