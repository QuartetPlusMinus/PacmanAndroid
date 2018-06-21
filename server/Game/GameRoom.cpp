//
// Created by viewsharp on 27.04.18.
//

#include "GameRoom.h"

GameRoom::GameRoom(const TileMap *map) :
        map(map),
        gameOver(false),
        ready(false),
        started(false),
        killedPacmans(0),
        lastStepTime(std::chrono::steady_clock::now()) {
    gameGraph.setUp(map->map());
}

void GameRoom::addClient(std::shared_ptr<Client> client) {
    players.push_back(std::make_shared<Pacman>(client));
    if (players.size() == map->pacman_size()) {
        ready = true;
    }
}

void GameRoom::connect(Client *client) {
    Messages::StartMessage startMessage;

    // TODO: make template Fabryc

    for (int i = 0; i < map->pacman_size(); i++) {
        Samples::UnitInit *unitInit = startMessage.add_unit();
        *unitInit->mutable_data() = *dynamic_cast<Samples::Unit*>(players[i].get());
        unitInit->set_name(players[i]->client->getUsername());
        unitInit->set_type(Samples::PACMAN);
    }

    for (int i = 0; i < map->ghost_size(); i++) {
        Samples::UnitInit *unitInit = startMessage.add_unit();
        *unitInit->mutable_data() = *dynamic_cast<Samples::Unit*>(ghosts[i].get());
        unitInit->set_type(Samples::GHOST);
    }

    client->Start(startMessage);
}

void GameRoom::start() {
    std::cout << "Game started" << std::endl;

    Messages::StartMessage startMessage;

    if (map->pacman_size() != players.size()) {
        throw PlayerCountException("Count of added players not equal map players count");
    }

    for (int i = 0; i < map->pacman_size(); i++) {

        // TODO: check copy constructors
        // TODO: Заменить на фабрику ?


        *players[i]->mutable_pos() = map->pacman(i);
        players[i]->set_direction(Samples::NONE);
        players[i]->set_entrypercent(0);
        players[i]->set_health(3);
        players[i]->set_status(Samples::ALIVE);

        Samples::UnitInit *unitInit = startMessage.add_unit();
        *unitInit->mutable_data() = *dynamic_cast<Samples::Unit*>(players[i].get());
        unitInit->set_name(players[i]->client->getUsername());
        unitInit->set_type(Samples::PACMAN);
    }

    for (int i = 0; i < map->ghost_size(); i++) {

        // TODO: check copy constructors
        // TODO: Заменить на фабрику

        auto currentGhost = std::make_shared<Ghost>(players);
        *currentGhost->mutable_pos() = map->ghost(i);
        currentGhost->set_direction(Samples::NONE);
        currentGhost->set_entrypercent(0);

        currentGhost->choiceDirection(gameGraph);

        ghosts.push_back(currentGhost);

        Samples::UnitInit *unitInit = startMessage.add_unit();
        *unitInit->mutable_data() = *dynamic_cast<Samples::Unit*>(ghosts[i].get());
        unitInit->set_type(Samples::GHOST);
    }

    for (Serialization::uint8 i = 0; i < map->pacman_size(); i++) {
        startMessage.set_id(i);
        players[i]->client->Start(startMessage);
    }

    started = true;
}

void GameRoom::step() {

    auto sleep_time = std::chrono::duration_cast<std::chrono::milliseconds>(
            period - (std::chrono::steady_clock::now() - lastStepTime));
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));


    Messages::IterationMessage iterationMessage;
    for (auto pacman: players) {
        pacman->step(gameGraph);
        pacman->setRoundPosition();
        *iterationMessage.add_unit() = *dynamic_cast<Samples::Unit*>(pacman.get());
    }

    for (auto ghost: ghosts) {
        ghost->step(gameGraph);
        ghost->setRoundPosition();
        *iterationMessage.add_unit() = *dynamic_cast<Samples::Unit*>(ghost.get());
    }

    checkGhostPacmanCollision();

    for (auto pacman: players) {
        if (pacman->status() == Samples::UnitStatus::KILLED) {
            ++killedPacmans;
        }
        pacman->client->Iteration(iterationMessage);
    }

    if (killedPacmans == map->pacman_size()) {
        gameOver = true;
    }

    lastStepTime = std::chrono::steady_clock::now();
}


std::shared_ptr<Pacman> GameRoom::getPacman(const std::shared_ptr<Client> client) const {

    for (auto pacman: players) {
        if (client == pacman->client) {
            return pacman;
        }
    }
    return nullptr;
}

void GameRoom::checkGhostPacmanCollision() {
    for (auto &pacman: players) {
        for (auto &ghost: ghosts) {
//            if (pacman->rPos == ghost->rPos) {
            if (pacman->pos().x() == ghost->pos().x() && pacman->pos().y() == ghost->pos().y()){
                if (!pacman->injured and pacman->status() != Samples::UnitStatus::DYING) {
                    pacman->injured = true;
                    pacman->injuredTimer = GameTimer::INJURED_TIMER / GameTimer::PERIOD;

                    pacman->set_health(static_cast<sz::uint8> (pacman->health() == 0 ? 0 : pacman->health() - 1));

                    std::cout << "HP " << (int) pacman->health() << std::endl;
                    if (pacman->health() == 0) {
                        pacman->set_status(Samples::UnitStatus::DYING);
                    }
                }
            }
        }
    }

}