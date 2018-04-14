//
// Created by viewsharp on 12.04.18.
//

#ifndef PACMANANDROID_FILE_DATA_H
#define PACMANANDROID_FILE_DATA_H


#include <android/asset_manager.h>

#pragma once
typedef struct {
    const long data_length;
    const void* data;
    const void* file_handle;
} FileData;

FileData create_file_data(const char* relative_path, AAssetManager *asset_manager);

#endif //PACMANANDROID_FILE_DATA_H
