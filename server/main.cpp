#include <iostream>
#include "Game.h"


//typedef unsigned long size_t;
static const unsigned short PORT = 31415;

int main() {
    Game game(PORT);
    game.start();
}