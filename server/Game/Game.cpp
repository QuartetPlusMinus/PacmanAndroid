//
// Created by views on 13.05.18.
//

#include "Game.h"

Game::Game(unsigned short port) :
        Service(port),
        mapManager(MapManager::Instance()) {
    currentMap = mapManager->getRandomMap();
}


void Game::start() {
    run();
}

void Game::Connect(std::shared_ptr<Client> client, Messages::ConnectMessage &connectMsg) {
    client->setUsername(connectMsg.name());
    if (client->getStatus() == Client::OUT_OF_GAME) {  // если клиент вне игры, то добавить его в очередь
        clientsQueue.push_back(client);
        client->setStatus(Client::IN_QUEUE);
    }
    if (client->getStatus() == Client::IN_GAME) {
        // reconnect
        if (clientInRoom.count(client->hash()) != 0) {

            if (clientInRoom[client->hash()]->gameOver) {
//                client->End(); // TODO: dodelt'
            } else {
                clientInRoom[client->hash()]->connect(client.get());
            }
        }
        return;
    }
    std::cout << "Client connected to server. Username: " << connectMsg.name() << endl;

    if (clientsQueue.size() >= currentMap->pacman_size()) { // Если набралось нужное кол-во пользователей

        // Создание комнаты
        GameRoom *newGameRoom = manager.AddRoom(currentMap);
        currentMap = mapManager->getRandomMap();

        if (newGameRoom != nullptr) {
            // Добавление клиентов в комнату
            for (unsigned int i = 0; i < currentMap->pacman_size(); i++) {
                Client *currentClient = clientsQueue.front().get(); // TODO: add shared ptr
                newGameRoom->addClient(currentClient);
                clientsQueue.erase(clientsQueue.begin());
                clientInRoom[currentClient->hash()] = newGameRoom;  // Добавление в таблицу клиент - комната
                currentClient->setStatus(Client::IN_GAME);
            }

            // Оправка остальным клиентам нового положения в очереди
            Messages::QueueMessage queueReply;
            for (sz::uint16 i = 0; i < clientsQueue.size(); ++i) {
                queueReply.set_position(i);
                clientsQueue[i]->Queue(queueReply);
            }
        }
    } else {
        // Если комната не набралась, то отсылаем статус в очереди
        Messages::QueueMessage queueReply;
        queueReply.set_position(static_cast<sz::uint8>(clients.size()));
        client->Queue(queueReply);
    }
}

void Game::Event(std::shared_ptr<Client> client, Messages::EventMessage &eventMsg) {
    if (client->getStatus() != Client::IN_GAME) {
        return;
    }

    if (clientInRoom.count(client->hash()) > 0) {
        std::cout << "Client " << client->getUsername() << " send event to server\n"; // TODO: remove to release
        auto room = clientInRoom[client->hash()];
        auto pacman = room->getPacman(client->getUsername());
        if (pacman) {
            pacman->newDirection = eventMsg.direction();
        }
    }
}
