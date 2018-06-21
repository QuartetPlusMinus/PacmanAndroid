//
// Created by views on 26.05.18.
//

#include "Pacman.h"

Pacman::Pacman(std::shared_ptr<Client> client) : client(client),
                                 newDirection(Samples::Direction::NONE),
                                 injured(false),
                                 injuredTimer(0),
                                 dyingTimer(GameTimer::DYING_TIMER / GameTimer::PERIOD) {}


bool Pacman::haveCollision(SetGraph &gameMap, Samples::Direction direction) {
    int currentVertex = pos().y() * GameMap::WIDTH + pos().x();
    auto nextTiles = gameMap.getNextVertices(currentVertex);

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


bool Pacman::step(SetGraph &gameMap) {
    bool result = false;

    if (injuredTimer == 0 and injured == true) {
        injured = false;
    }
    if (dyingTimer == 0) {
        this->set_status(Samples::UnitStatus::KILLED);

        Messages::EndMessage endMessage;

        endMessage.set_status(Samples::GameStatus::LOSE);
        endMessage.set_points(777);
        client->setStatus(Client::OUT_OF_GAME);
    }

    if (dyingTimer > 0 && health() == 0) {
        --dyingTimer;
    }

    if (injuredTimer > 0) {
        --injuredTimer;
    }

    if (direction() != Samples::Direction::NONE) {
        this->set_entrypercent(this->entrypercent() + UnitParametrs::PERCENTS);
        if (this->entrypercent() >= 1.0f) {
            stepToDirection(direction());
            this->set_entrypercent(0.0f);
        }
    }

    if (newDirection != Samples::Direction::NONE) {
        if (entrypercent() == 0.0f) {
            if (!haveCollision(gameMap, newDirection)) {
                this->set_direction(newDirection);
            }
            newDirection = Samples::Direction::NONE;
            result = true;
        } else if ((direction() == Samples::RIGHT && newDirection == Samples::LEFT) ||
                   (direction() == Samples::LEFT && newDirection == Samples::RIGHT) ||
                   (direction() == Samples::UP && newDirection == Samples::DOWN) ||
                   (direction() == Samples::DOWN && newDirection == Samples::UP)) {
            stepToDirection(direction());
            set_entrypercent(1.0f - entrypercent());
            this->set_direction(newDirection);
            return true;
        }
    }

    if (haveCollision(gameMap, direction())) {
        set_direction(Samples::NONE);
        return true;
    }

    return result;
}

void Pacman::stepToDirection(Samples::Direction direction) {
    switch (direction) {
        case Samples::Direction::RIGHT:
            this->mutable_pos()->set_x(static_cast<sz::uint8>(this->pos().x() + 1));
            break;
        case Samples::Direction::LEFT:
            this->mutable_pos()->set_x(static_cast<sz::uint8>(this->pos().x() - 1));
            break;
        case Samples::Direction::UP:
            this->mutable_pos()->set_y(static_cast<sz::uint8>(this->pos().y() - 1));
            break;
        case Samples::Direction::DOWN:
            this->mutable_pos()->set_y(static_cast<sz::uint8>(this->pos().y() + 1));
            break;
        default:
            break;
    }

}


void Pacman::setRoundPosition() {
    rPos.setPosition(pos().x(), pos().y(), direction(), entrypercent());
}