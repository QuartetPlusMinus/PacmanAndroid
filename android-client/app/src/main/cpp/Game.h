#ifndef ANDROID_CLIENT_GAME_H
#define ANDROID_CLIENT_GAME_H

#include <vector>

#include <Serialization/Messages.h>

#include "IDrawable.h"
#include "Background.h"
#include "Unit.h"

class Game {
public:
    Game() : started(false) {}

    void onSurfaceCreated();

    void onSurfaceChanged(int width, int height);

    void onDrawFrame();

    void setAssertManager(AAssetManager* assetManager);

    void start(Messages::StartMessage &startMessage);

    void iterate(Messages::IterationMessage &iterationMessage);

    void end(Messages::EndMessage &endMessage);

    bool isStarted();

private:

    int id;
    Background background;
//    Point *points;
    Unit **units;
    int unitsCount;
    bool started;
    AAssetManager* assetManager;
};

#endif // ANDROID_CLIENT_GAME_H