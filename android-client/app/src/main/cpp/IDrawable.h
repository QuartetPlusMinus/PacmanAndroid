//
// Created by views on 08.06.18.
//

#ifndef ANDROID_CLIENT_IDRAWABLE_H
#define ANDROID_CLIENT_IDRAWABLE_H

#include "libodraw/libodraw.h"

class IDrawable {
public:
    virtual void init() = 0;
    virtual void draw() = 0;
};

#endif //ANDROID_CLIENT_IDRAWABLE_H
