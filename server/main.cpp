#include <iostream>
#include "Game/Game.h"

static const unsigned short PORT = 31415;

int main() {
    Game game(PORT);
    game.start();
}