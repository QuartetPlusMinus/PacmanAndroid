//
// Created by views on 08.06.18.
//

#ifndef ANDROID_CLIENT_RECTANGLE_H
#define ANDROID_CLIENT_RECTANGLE_H

#include "linmath.h"

namespace OpenDraw {
    class Rectangle {
    public:
        Rectangle(float x1, float y1, float x2, float y2) :
                x1(x1),
                y1(y1),
                x2(x2),
                y2(y2) {}

        const float x1;
        const float y1;
        const float x2;
        const float y2;
    };
}

#endif //ANDROID_CLIENT_RECTANGLE_H
