#include <jni.h>
#include <android/asset_manager_jni.h>

#include "macros.h"
#include "program.h"
/* Header for class com_example_viewsharp_pacman_RendererWrapper */

#ifndef _Included_com_example_viewsharp_pacman_Game
#define _Included_com_example_viewsharp_pacman_Game

class Game {
public:

    Game() = default;

    void onSurfaceCreated();

    void onSurfaceChanged(int width, int height);

    void onDrawFrame();

    void start(char *message, size_t size);

    void iterate(char *message, size_t size);

    void end(char *message, size_t size);
};


#endif //_Included_com_example_viewsharp_pacman_Game