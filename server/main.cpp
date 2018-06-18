#include <iostream>
#include "Game/lib/Game.h"

static const unsigned short PORT = 31415;

int main() {
    Messages::SimpleTypes::Stream stream;
    for (int i = 0; i <= 256; i++) {
        stream << (char)i;
    }
    string string1 = stream.str();

    Game game(PORT);
    game.start();
}