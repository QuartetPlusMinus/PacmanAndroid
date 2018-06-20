//
// Created by views on 13.05.18.
//

#include "Game.h"

Game::Game(unsigned short port) : Service(port) {
}


void Game::start() {
//        std::thread gameStepsMaker(steps, std::ref(canAddGameRooms), std::ref(rooms));
//        gameStepsMaker.detach();
    run();
//        boost::thread thread([this]() { this->run(); });
//        thread.detach();
//        thread.join();
    std::cout << "Я дошел до этой точки!" << std::endl;
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
//                client->End();
            } else {
                clientInRoom[client->hash()]->connect(client.get());
            }
        }
//        connect(client);
        return;
    }
    std::cout << "Client connected to server. Username: " << connectMsg.name() << endl;

    if (clientsQueue.size() >= clientsCountInRoom) { // Если набралось нужное кол-во пользователей
        //

        // Создаём комнату
        GameRoom *newGameRoom = manager.AddRoom();
        if (newGameRoom != nullptr) {
            // Добавление клиентов в комнату
            for (unsigned int i = 0; i < clientsCountInRoom; i++) {
                Client *currentClient = clientsQueue.front().get(); // TODO: add shared ptr
                newGameRoom->addClient(currentClient);
                clientsQueue.erase(clientsQueue.begin());
                clientInRoom[currentClient->hash()] = newGameRoom;  // Добавление в таблицу клиент - комната
                currentClient->setStatus(Client::IN_GAME);
            }

//            newGameRoom->start();

            // Оправка остальным клиентам нового положения в очереди
            Messages::QueueMessage queueReply;
            for (int i = 0; i < clientsQueue.size(); ++i) {
                queueReply.set_position((sz::uint16) i);
                clientsQueue[i]->Queue(queueReply);
            }


        }

//            try {
//                room->start();
//            } catch (PlayerCountException *e) {
//                cout << e->what();
//            }


    } else {

        // Если комната не набралась, то отсылаем статус в очереди
        Messages::QueueMessage queueReply;
        queueReply.set_position((sz::uint16) clients.size());
        client->Queue(queueReply);
    }
}

void Game::Event(std::shared_ptr<Client> client, Messages::EventMessage &eventMsg) {
    if(client->getStatus() != Client::IN_GAME) {
        return;
    }
    if (clientInRoom.find(client->hash()) != clientInRoom.end()) {
        std::cout << "Client " << client->getUsername() << " send event to server\n";
        auto room = clientInRoom[client->hash()];
        auto pacman = room->getPacman(client->getUsername());
        if(pacman) {
            pacman->newDirection = eventMsg.direction();
        }
    }
}
