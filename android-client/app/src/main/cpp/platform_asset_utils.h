#include <string>
#include <jni.h>
#include <android/asset_manager_jni.h>
#include "platform_file_utils.h"
#include "macros.h"

FileData get_asset_data(const char* relative_path);
void release_asset_data(const FileData* file_data);

#ifndef _Included_com_example_viewsharp_pacman_RendererWrapper_asset
#define _Included_com_example_viewsharp_pacman_RendererWrapper_asset

static AAssetManager* asset_manager;

#endif