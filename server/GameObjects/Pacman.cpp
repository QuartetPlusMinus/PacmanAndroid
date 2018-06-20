//
// Created by views on 26.05.18.
//

#include "Pacman.h"

Pacman::Pacman(Client *client) : client(client), newDirection(Samples::Direction::NONE) {
}


bool Pacman::haveCollision(SetGraph &gameMap, Samples::Direction direction) {
    int currentVertex = pos().y() * GameMap::WIDTH + pos().x();
    auto nextTiles = gameMap.GetNextVertices(currentVertex);

    int nextVertex = currentVertex;

    switch (direction) {
        case Samples::Direction::RIGHT:
            nextVertex += 1;
            break;
        case Samples::Direction::LEFT:
            nextVertex -= 1;
            break;
        case Samples::Direction::DOWN:
            nextVertex += GameMap::WIDTH;
            break;
        case Samples::Direction::UP:
            nextVertex -= GameMap::WIDTH;
            break;
        default:
            break;
    }
    for (auto tile: nextTiles) {
        if (tile == nextVertex) {
            return false;
        }
    }
    return true;
}


void Pacman::step(SetGraph &gameMap) {
    if (direction() != Samples::Direction::NONE) {
        this->set_entrypercent(this->entrypercent() + 0.25f);
        if (this->entrypercent() >= 1.0f) {
            stepToDirection(direction());
            this->set_entrypercent(0.0f);
        }
    }

    if (newDirection != Samples::Direction::NONE) {
        if (entrypercent() == 0.0f) {
            if (!haveCollision(gameMap, newDirection)){
                this->set_direction(newDirection);
            }
            newDirection = Samples::Direction::NONE;
        } else if ((direction() == Samples::RIGHT && newDirection == Samples::LEFT) ||
                   (direction() == Samples::LEFT && newDirection == Samples::RIGHT) ||
                   (direction() == Samples::UP && newDirection == Samples::DOWN) ||
                   (direction() == Samples::DOWN && newDirection == Samples::UP)) {
            stepToDirection(direction());
            set_entrypercent(1.0f - entrypercent());
            this->set_direction(newDirection);
            return;
        }
    }

    if (haveCollision(gameMap, direction())) {
        set_direction(Samples::NONE);
    }
}

void Pacman::stepToDirection(Samples::Direction direction) {
    switch (direction) {
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

}
