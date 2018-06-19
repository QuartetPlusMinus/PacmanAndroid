//
// Created by viewsharp on 01.05.18.
//

#include "Socket.h"

const bool operator==(const Token &left, const Token &right) {
    return left.rnd == right.rnd and left.tm == right.tm;
}

const bool operator==(const Token &left, char *&right) {
    return left.rnd == *(int *) right and left.tm == *(int *) (right + sizeof(int));
}