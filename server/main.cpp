#include <iostream>
#include "Game/lib/Game.h"

static const unsigned short PORT = 31415;

int main() {
    Game game(PORT);
    game.start();
}