//
// Created by viewsharp on 12.04.18.
//

#ifndef PACMANANDROID_GAMEOBJECTFACTORY_H
#define PACMANANDROID_GAMEOBJECTFACTORY_H

#include "Unit.h"
#include "Pacman.h"
#include "Ghost.h"

class GameObjectFactory {

public:
    GameObjectFactory() {
    }

//    GameOjectFactory(sf::Font &nameFont):
//            nameFont(nameFont){
//
//    }

    Unit *make(const BeingInit &data) {
        switch(data.type()) {
            case PACMAN:
                return new Pacman(data.name(), data.data()); //, nameFont);
            case GHOST:
                return new Ghost(data.data());
            default:
                break;
        }
    }

private:
//    sf::Font nameFont;

};

#endif //PACMANANDROID_GAMEOBJECTFACTORY_H
