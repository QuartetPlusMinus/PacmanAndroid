//
// Created by murt on 13.06.18.
//

#ifndef SERVER_GHOST_H
#define SERVER_GHOST_H


#include "../../common/Serialization/Samples.h"
#include "Pacman.h"
#include "../Graph/SetGraph.h"
#include "../../common/Constants/ConstValues.h"

class Ghost : public Samples::Unit {
public:
    Ghost(std::vector<Pacman *> &pacmans);

    Pacman *target;

    void choiceDirection(SetGraph &gameMap);

    void step(SetGraph &gameMap) {
        int curentVertex = pos().y() * GameMap::WIDTH + pos().x();
        auto nextTiles = gameMap.GetNextVertices(curentVertex);

        int nextVertex = curentVertex;

        Samples::Direction curentDirection = direction();
        switch (curentDirection) {
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
        bool haveCollision = true;
        for (auto tile: nextTiles) {
            if (tile == nextVertex) {
                haveCollision = false;
                break;
            }
        }
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
                (nextTiles.size() == 2 and (1 < abs(nextTiles[0] - nextTiles[1]) < 2 * GameMap::WIDTH))) {
                choiceDirection(gameMap);
            }
        }


        std::cout << (int) pos().x() << " - " << (int) pos().y() << std::endl;

    }

};


#endif //SERVER_GHOST_H
