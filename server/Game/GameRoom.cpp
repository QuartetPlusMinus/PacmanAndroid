//
// Created by viewsharp on 27.04.18.
//

#include "GameRoom.h"
#include "../Graph/setUpGraph.h"


GameRoom::GameRoom(const TileMap &map) :
        map(map), gameOver(false), ready(false), started(false), lastStepTime(std::chrono::steady_clock::now()) {
    gameGraph.setUp(map.map());
}

void GameRoom::addClient(Client *client) {

    players.push_back(new Pacman(client));
}

void GameRoom::connect(Client* client) {
    Messages::StartMessage startMessage;

    for (int i = 0; i < map.pacman_size(); i++) {
        Samples::UnitInit *unitInit = startMessage.add_unit();
        *unitInit->mutable_data() = *(Samples::Unit *) players[i];
        unitInit->set_name(players[i]->client->getUsername());
        unitInit->set_type(Samples::PACMAN);
    }

    for (int i = 0; i < map.ghost_size(); i++) {

        Samples::UnitInit *unitInit = startMessage.add_unit();
        *unitInit->mutable_data() = *(Samples::Unit *) ghosts[i];
        unitInit->set_type(Samples::GHOST);
    }

    client->Start(startMessage);
}

void GameRoom::start() {
    std::cout << "Game started" << std::endl;

    Messages::StartMessage startMessage;

    if (map.pacman_size() != players.size()) {
        throw PlayerCountException("Count of added players not equal map players count");
    }

    for (int i = 0; i < map.pacman_size(); i++) {

        // TODO: Заменить на фабрику ?

        *players[i]->mutable_pos() = map.pacman(i);
        players[i]->set_direction(Samples::NONE);
        players[i]->set_entrypercent(0);
        players[i]->set_health(3);
        players[i]->set_status(Samples::ALIVE);

        Samples::UnitInit *unitInit = startMessage.add_unit();
        *unitInit->mutable_data() = *(Samples::Unit *) players[i];
        unitInit->set_name(players[i]->client->getUsername());
        unitInit->set_type(Samples::PACMAN);
    }

    for (int i = 0; i < map.ghost_size(); i++) {

        // TODO: Рассчитать направления ghost'ов
        // TODO: Заменить на фабрику

        auto currentGhost = new Ghost(players);

        *currentGhost->mutable_pos() = map.ghost(i);
        currentGhost->set_direction(Samples::NONE);
        currentGhost->set_entrypercent(0);

        currentGhost->choiceDirection(gameGraph);

        ghosts.push_back(currentGhost);

        Samples::UnitInit *unitInit = startMessage.add_unit();
        *unitInit->mutable_data() = *(Samples::Unit *) ghosts[i];
        unitInit->set_type(Samples::GHOST);
    }

    for (Serialization::uint8 i = 0; i < map.pacman_size(); i++) {
        startMessage.set_id(i);
        players[i]->client->Start(startMessage);
    }

    ready = true;
    started = true;
}

void GameRoom::step() {

    auto sleep_time =  std::chrono::duration_cast<std::chrono::milliseconds>(period - (std::chrono::steady_clock::now() - lastStepTime));
    std::this_thread::sleep_for(std::chrono::milliseconds (sleep_time));

    Messages::IterationMessage iterationMessage;
    for( auto pacman: players){
       pacman->step(gameGraph);
        *iterationMessage.add_unit() = *(Samples::Unit *)pacman;
    }

    for(auto ghost: ghosts){
        ghost->step(gameGraph);
        *iterationMessage.add_unit() = *(Samples::Unit *)ghost;
    }

    for( auto pacman: players){
        pacman->client->Iteration(iterationMessage);
    }
    lastStepTime = std::chrono::steady_clock::now();
}


Pacman* GameRoom::getPacman(const std::string &username) {
    for(auto pacman: players ) {
        if(username == pacman->client->getUsername()) {
            return pacman;
        }
    }
    return nullptr;
}