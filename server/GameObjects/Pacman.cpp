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
    Samples::Direction currentDirection;

    if (newDirection != Samples::Direction::NONE) {

        if (!haveCollision(gameMap, newDirection)) {
            this->set_direction(newDirection);
            currentDirection = newDirection;

        } else if (!haveCollision(gameMap, direction())) {
            this->set_direction(direction());
            this->set_entrypercent(this->entrypercent() + 0.25f);
            currentDirection = direction();
        }
    } else if (!haveCollision(gameMap, direction())) {
        this->set_direction(direction());
        this->set_entrypercent(this->entrypercent() + 0.25f);
        currentDirection = direction();
    } else {
        this->set_direction(Samples::Direction::NONE);
    }
    newDirection = Samples::Direction::NONE;

    if (this->entrypercent() >= 1.0f) {
        switch (currentDirection) {
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
    }
}