//
// Created by views on 19.06.18.
//

#include "Serializable.h"

using namespace Serialization;

void Serializable::serializeToString(string &str) const {
    Stream distStream;
    serializeToStream(distStream);
    str = distStream.str();
}

void Serializable::parseFromString(string &str) {
    Stream srcStream(str);
    parseFromStream(srcStream);
}