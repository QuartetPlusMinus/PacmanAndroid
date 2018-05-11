#include <iostream>
#include "Service.h"
#include "Game.h"


typedef unsigned long size_t;

static const unsigned short initiatorPort = 27182; // client port
static const unsigned short receiverPort = 31415;

static int main() {
    Game game(initiatorPort, receiverPort);
    game.loop();
}