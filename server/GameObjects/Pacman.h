//
// Created by views on 26.05.18.
//

#ifndef SERVER_PLAYER_H
#define SERVER_PLAYER_H

#include "../NetWork/Client.h"
#include "../Graph/SetGraph.h"
#include "../../common/Constants/ConstValues.h"


class Pacman : public Samples::Unit {
public:
    explicit Pacman(Client *client) :
            client(client), newDirection(Samples::Direction::NONE) {

    }

    const Client *client;

    Samples::Direction newDirection;

    bool haveCollision(SetGraph &gameMap, Samples::Direction direction) {
        int curentVertex = pos().y() * GameMap::WIDTH + pos().x();
        auto nextTiles = gameMap.GetNextVertices(curentVertex);

        int nextVertex = curentVertex;

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

    void step(SetGraph &gameMap) {


        Samples::Direction curentDirection;
//                newDirection != Samples::Direction::NONE ? newDirection : direction();

//        newDirection = Samples::Direction::NONE;
        if (newDirection != Samples::Direction::NONE) {
//            bool differentDirection = newDirection == direction();

            if (!haveCollision(gameMap, newDirection)) {
                this->set_direction(newDirection);
                curentDirection = newDirection;

            } else if (!haveCollision(gameMap, direction())) {
                this->set_direction(direction());
                this->set_entrypercent(this->entrypercent() + 0.25f);
                curentDirection = direction();
            }
        } else if (!haveCollision(gameMap, direction())) {
            this->set_direction(direction());
            this->set_entrypercent(this->entrypercent() + 0.25f);
            curentDirection = direction();
        } else {
            this->set_direction(Samples::Direction::NONE);
        }
        newDirection = Samples::Direction::NONE;

        if (this->entrypercent() >= 1.0f) {
            switch (curentDirection) {
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
//        } else {
//            this->set_direction(Samples::NONE);
//        }


    }
};

#endif //SERVER_PLAYER_H
