#include <iostream>
#include "Game.h"


typedef unsigned long size_t;

//static const unsigned short initiatorPort = 27182; // client port
static const unsigned short PORT = 31415;

int main() {
//    Service service(receiverPort);
//    service.run();
    Game game(PORT);
    game.start();
}