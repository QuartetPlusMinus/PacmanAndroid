//
// Created by viewsharp on 11.04.18.
//

#include <vector>
#include "game.h"
#include "game_objects.h"
#include "asset_utils.h"
#include "buffer.h"
#include "image.h"
#include "linmath.h"
#include "math_helper.h"
#include "matrix.h"
#include "platform_gl.h"
#include "platform_asset_utils.h"
#include "shader.h"
#include "texture.h"
#include "GameObjects/Unit.h"

//static const float puck_height = 0.02f;
//static const float mallet_height = 0.15f;

static Table table;
static std::vector<Unit> units;
//static Puck puck;
//static Mallet red_mallet;
//static Mallet blue_mallet;

static TextureProgram texture_program;
static ColorProgram color_program;

//static mat4x4 projection_matrix;
//static mat4x4 model_matrix;
//static mat4x4 view_matrix;
//
//static mat4x4 view_projection_matrix;
//static mat4x4 model_view_projection_matrix;

//static void position_table_in_scene();
//static void position_object_in_scene(float x, float y, float z);

static float pos = 0.0f;

void onSurfaceCreated() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //
    glEnable(GL_DEPTH_TEST); //

    table = create_table(load_png_asset_into_texture("textures/map.png"));

//    vec4 puck_color = {0.8f, 0.8f, 1.0f, 1.0f}; //
//    vec4 red = {1.0f, 0.0f, 0.0f, 1.0f}; //
//    vec4 blue = {0.0f, 0.0f, 1.0f, 1.0f}; //

//    puck = create_puck(0.06f, puck_height, 32, puck_color);
//    red_mallet = create_mallet(0.08f, mallet_height, 32, red);
//    blue_mallet = create_mallet(0.08f, mallet_height, 32, blue);

    texture_program = get_texture_program(); //
    color_program = get_color_program(); //
}

void onSurfaceChanged(int width, int height) {
    glViewport(0, 0, width, height);
//    mat4x4_perspective(projection_matrix, 45, (float) width / (float) height, 1, 10);
//    mat4x4_look_at(view_matrix, 0.0f, 1.2f, 2.2f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
}

void onDrawFrame() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    mat4x4_mul(view_projection_matrix, projection_matrix, view_matrix);

//    position_table_in_scene();
    draw_table(&table, &texture_program); //, model_view_projection_matrix);

//    position_object_in_scene(0.0f, mallet_height / 2.0f, -0.4f);
//    draw_mallet(&red_mallet, &color_program); //, model_view_projection_matrix);

//    position_object_in_scene(pos, mallet_height / 2.0f, 0.4f);
//    draw_mallet(&blue_mallet, &color_program); //, model_view_projection_matrix);

//    pos += 0.01f;

    // Draw the puck.
//    position_object_in_scene(0.0f, puck_height / 2.0f, 0.0f);
//    draw_puck(&puck, &color_program); //, model_view_projection_matrix);
}