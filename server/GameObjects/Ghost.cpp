//
// Created by murt on 13.06.18.
//

#include <queue>
#include <unordered_set>
#include <random>
#include <bits/unordered_map.h>
#include "Ghost.h"
#include <Constants/ConstValues.h>


Ghost::Ghost(std::vector<Pacman *> &pacmans) {
    std::random_device random_device;
    std::mt19937 engine{random_device()};
    std::uniform_int_distribution<int> dist(0, (int) pacmans.size() - 1);
    target = pacmans[dist(engine)];
}

void Ghost::choiceDirection(SetGraph &gameMap) {

    int startVertex = this->pos().x() + GameMap::WIDTH * this->pos().y();
    int goalVertex = target->pos().x() + GameMap::WIDTH * target->pos().y();
    std::queue<int> frontier;
    frontier.push(startVertex);
    std::unordered_set<int> visited;
    visited.insert(startVertex);
    std::unordered_map<int, int> cameFrom;

    // поиск кратчайшего пути до pacman'а
    while (frontier.size() > 0) {
        int curent = frontier.front();
        frontier.pop();
        for (auto next: gameMap.GetNextVertices(curent)) {
            if (visited.count(next) == 0) {
                frontier.push(next);
                visited.insert(next);
                cameFrom.insert({next, curent});
            }
        }
    }

    // восстановление пути
    int current = goalVertex;
    int prev = startVertex;
    while (current != startVertex) {
        prev = current;
        current = cameFrom[current];
    }

    Samples::Direction dir;
    int difference = prev - current;
    switch (difference) {
        case 1:
            dir = Samples::RIGHT;
            break;
        case -1:
            dir = Samples::LEFT;
            break;
        case GameMap::WIDTH:
            dir = Samples::DOWN;
            break;
        case -GameMap::WIDTH:
            dir = Samples::UP;
            break;
        default:
            dir = Samples::NONE;
            break;
    }
    this->set_direction(dir);
}


void Ghost::step(SetGraph &gameMap) {
    int currentVertex = pos().y() * GameMap::WIDTH + pos().x();
    auto nextTiles = gameMap.GetNextVertices(currentVertex);

    this->set_entrypercent(this->entrypercent() + 0.25f);

    if (this->entrypercent() >= 1.0f) {
        switch (this->direction()) {
            case Samples::Direction::RIGHT:
                this->mutable_pos()->set_x((sz::uint8) (this->pos().x() + 1));
                break;
            case Samples::Direction::LEFT:
                this->mutable_pos()->set_x((sz::uint8) (this->pos().x() - 1));
                break;
            case Samples::Direction::UP:
                this->mutable_pos()->set_y((sz::uint8) (this->pos().y() - 1));
                break;
            case Samples::Direction::DOWN:
                this->mutable_pos()->set_y((sz::uint8) (this->pos().y() + 1));
                break;
            default:
                break;
        }
        this->set_entrypercent(0.0f);
        if (nextTiles.size() == 1 ||
            (nextTiles.size() == 2 and (2 < abs(nextTiles[0] - nextTiles[1]) < 2 * GameMap::WIDTH)) ||
            nextTiles.size() > 2) {
            choiceDirection(gameMap);
        }
    }
}