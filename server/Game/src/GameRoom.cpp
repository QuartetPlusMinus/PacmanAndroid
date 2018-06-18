//
// Created by viewsharp on 27.04.18.
//

#include "../lib/GameRoom.h"

//GameRoom::GameRoom(): map(nullptr) {}

GameRoom::GameRoom(GameMap::Map *map) :
        map(map), gameOver(false), ready(false) {}

void GameRoom::addClient(Client *client) {

    // TODO: добавить игрока

    players.push_back(new Pacman(client));
}

void GameRoom::connect(Client* client) {
    Messages::StartMessage startMessage;

    for (int i = 0; i < map->playersCount; i++) {
        Messages::UnitInit *unitInit = startMessage.add_unit();
        *unitInit->mutable_data() = *(Messages::Unit *) players[i];
        unitInit->set_name(players[i]->client->getUsername());
        unitInit->set_type(Messages::PACMAN);
    }

    for (int i = 0; i < map->ghostsCount; i++) {

        Messages::UnitInit *unitInit = startMessage.add_unit();
        *unitInit->mutable_data() = *(Messages::Unit *) ghosts[i];
        unitInit->set_type(Messages::GHOST);
    }

    client->Start(startMessage);



}

void GameRoom::start() {
    std::cout << "Game started" << std::endl;


    // TODO: инициализирует объекты игры

    Messages::StartMessage startMessage;

    if (map->playersCount != players.size()) {
        throw PlayerCountException("Count of added players not equal map players count");
    }

//    ghosts.reserve(map->ghostsCount);

    for (int i = 0; i < map->playersCount; i++) {

        // TODO: Заменить на фабрику ?

        *players[i]->mutable_pos() = map->playersPositions[i];
        players[i]->set_direction(Messages::NONE);
        players[i]->set_entrypercent(0);
        players[i]->set_health(3);
        players[i]->set_status(Messages::ALIVE);

        Messages::UnitInit *unitInit = startMessage.add_unit();
        *unitInit->mutable_data() = *(Messages::Unit *) players[i];
        unitInit->set_name(players[i]->client->getUsername());
        unitInit->set_type(Messages::PACMAN);
    }

    for (int i = 0; i < map->ghostsCount; i++) {

        // TODO: Рассчитать направления ghost'ов
        // TODO: Заменить на фабрику

        auto currentGhost = new Ghost();

        *currentGhost->mutable_pos() = map->ghostsPositions[i];
        currentGhost->set_direction(Messages::NONE);
        currentGhost->set_entrypercent(0);

        ghosts.push_back(currentGhost);

        Messages::UnitInit *unitInit = startMessage.add_unit();
        *unitInit->mutable_data() = *(Messages::Unit *) ghosts[i];
//        unitInit->set_name(players[i]->client->getUsername());
        unitInit->set_type(Messages::GHOST);
    }

    for (Messages::uint8 i = 0; i < map->playersCount; i++) {
        startMessage.set_id(i);
        players[i]->client->Start(startMessage);
    }

    ready = true;

}

void GameRoom::step() {
    Messages::IterationMessage iterationMessage;
    for( auto pacman: players){
       pacman->step();
        *iterationMessage.add_unit() = *(Messages::Unit *)pacman;
//        auto unit = iterationMessage.add_unit();
    }
    for(auto ghost: ghosts){
        ghost->step();
        *iterationMessage.add_unit() = *(Messages::Unit *)ghost;
    }

    for( auto pacman: players){
        pacman->client->Iteration(iterationMessage);
        std::cout << "Send iteration" << std::endl;
    }

}