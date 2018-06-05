//
// Created by viewsharp on 27.04.18.
//

#include "GameRoom.h"

GameRoom::GameRoom(GameMap::Map *map) :
        map(map) {}

void GameRoom::addClient(Client *client) {

    // TODO: добавить игрока

    players.push_back(new Player(client));
}

void GameRoom::start() {

    // TODO: инициализирует объекты игры

    StartMessage startMessage;

    if (map->playersCount != players.size()) {
        throw PlayerCountException("Count of added players not equal map players count");
    }

//    ghosts.reserve(map->ghostsCount);

    for (int i = 0; i < map->playersCount; i++) {

        // TODO: Заменить на фабрику ?

        *players[i]->mutable_pos() = map->playersPositions[i];
        players[i]->pos();
        players[i]->release_pos();
        players[i]->set_direction(RIGHT);
        players[i]->set_entrypercent(0);
        players[i]->set_health(3);
        players[i]->set_status(ALIVE);

        UnitInit *unitInit = startMessage.add_unit();
        *unitInit->mutable_data() = *(Unit *) players[i];
        unitInit->set_name(players[i]->client->getUsername());
        unitInit->set_type(PACMAN);
    }

    for (int i = 0; i < map->ghostsCount; i++) {

        // TODO: Рассчитать направления ghost'ов
        // TODO: Заменить на фабрику

        Unit *currentGhost = new Unit();

        *currentGhost->mutable_pos() = map->ghostsPositions[i];
        currentGhost->set_direction(RIGHT);
        currentGhost->set_entrypercent(0);

        ghosts.push_back(currentGhost);

        UnitInit *unitInit = startMessage.add_unit();
        *unitInit->mutable_data() = *(Unit *) ghosts[i];
//        unitInit->set_name(players[i]->client->getUsername());
        unitInit->set_type(GHOST);
    }

    for (unsigned int i = 0; i < map->playersCount; i++) {
        startMessage.set_id(i);
        players[i]->client->Start(startMessage);
    }
}
