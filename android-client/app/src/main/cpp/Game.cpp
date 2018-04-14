//
// Created by viewsharp on 11.04.18.
//

#include "Game.h"

Game::Game(AAssetManager* assetManager):
        manager(assetManager)
{

    // ------------------------------------ Connect to server --------------------------------------
    ConnectRequest connectRequest;
    connectRequest.set_name(name);

    auto connectReply = connection->Connect(connectRequest);

    connection->setHex(connectReply->hex());

    delete connectReply;
    // ---------------------------------------------------------------------------------------------


    // ------------------------------------ Init game ----------------------------------------------
    StartReply *startReply;
    StartRequest startRequest;

    // Wait when server give game data
    while (true) {
        startReply = connection->Start(startRequest);
//            cout<<"Start: sleep = " << startReply->time() << endl;
        if (startReply->time() == 0)
            break;
        usleep((useconds_t)startReply->time());
        delete  startReply;
    }

    // Init game units
    unitCount = startReply->being_size();
    units = new Unit *[unitCount];

    GameObjectFactory factory;

    for (int i = 0; i < beingCount; i++) {
        units[i] = factory.make(startReply->being(i));
    }

    id = startReply->id();
    direction = beings[id]->direction();

    drawer_init();

    TileMap tMap(startReply, &window);

    delete startReply;
    // ---------------------------------------------------------------------------------------------
}

void Game::changeSurface(unsigned int width, unsigned int height) {
    drawer_set_view_port(0, 0, width, height);
}

void Game::draw() {

    // Here was the event handler!


    // ------------------------------------ Game iteration -----------------------------------------
    IterationRequest request;
    request.set_direction(direction);

    auto reply = connection->Iteration(request);

    direction = reply->being(id).direction();
    ((Pacman*)beings[id])->setSide(1);

    for (int i = 0; i < reply->coins_size(); i++) {
        coin.setPosition(reply->coins(i).x() * 32 + 40 ,reply->coins(i).y() * 32 + 40);
        window.draw(coin);
    }

    for (int i = 0; i < beingCount; i++) {
        beings[i]->setData(reply->being(i));
        beings[i]->draw(&window);
    }

    bool result = (reply->coins_size() == 0);

    delete reply;
    // ---------------------------------------------------------------------------------------------
}

void Game::over() {
    EndRequest endRequest;
    auto endReply = connection->End(endRequest);
    cout << "points = " << endReply->points();

    sf::Text gameStatus;
    sf::Text gamePoints;

    gameStatus.setFont(font);
    gamePoints.setFont(font);
    gamePoints.setString("Your score  " + std::to_string(endReply->points()));
    gamePoints.setCharacterSize(50);
    gamePoints.setColor(sf::Color::Red);
    gamePoints.setPosition(200,300);

    if (endReply->status() == WIN) {
        gameStatus.setString("YOU WIN!");
    } else {
        gameStatus.setString("LOL, YOU LOSE");
    }
    delete endReply;
    gameStatus.setCharacterSize(50);
    gameStatus.setColor(sf::Color::Red);
    gameStatus.setPosition(200,200);

    window.clear();

    window.draw(gameStatus);
    window.draw(gamePoints);
    window.display();

    // Here was the close event handler
}