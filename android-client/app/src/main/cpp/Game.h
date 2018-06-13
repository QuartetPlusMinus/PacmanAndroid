#ifndef ANDROID_CLIENT_GAME_H
#define ANDROID_CLIENT_GAME_H

#include <vector>

#include "macros.h"
#include "IDrawable.h"
#include "Background.h"
#include "Units.h"

class Game {
public:
    Game() = default;

    void onSurfaceCreated();

    void onSurfaceChanged(int width, int height);

    void onDrawFrame();

    void start(Messages::StartMessage &startMessage);

    void iterate(Messages::IterationMessage &iterationMessage);

    void end(Messages::EndMessage &endMessage);

private:

    int id;
    Background background;
//    Point *points;
    Unit **units;
    int unitsCount;
};

#endif // ANDROID_CLIENT_GAME_H