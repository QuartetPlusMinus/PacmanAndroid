#include <jni.h>
#include <android/asset_manager_jni.h>
#include <vector>

#include "macros.h"
#include "program.h"
#include "IDrawable.h"
#include "Background.h"
/* Header for class com_example_viewsharp_pacman_RendererWrapper */

#ifndef _Included_com_example_viewsharp_pacman_Game
#define _Included_com_example_viewsharp_pacman_Game

static TextureProgram texture_program;
static ColorProgram color_program;

class Game {
public:
    Game() = default;

    void onSurfaceCreated();

    void onSurfaceChanged(int width, int height);

    void onDrawFrame();

    void start(char *message, size_t size);

    void iterate(char *message, size_t size);

    void end(char *message, size_t size);

private:

    static Background background;
    static std::vector<IDrawable> units;
};


#endif //_Included_com_example_viewsharp_pacman_Game