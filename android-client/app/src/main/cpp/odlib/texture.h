//
// Created by viewsharp on 12.04.18.
//

#ifndef PACMANANDROID_TEXTURE_H
#define PACMANANDROID_TEXTURE_H

typedef struct {
    const char *src;
} Texture;

Texture create_texture(const char* src);

#endif //PACMANANDROID_TEXTURE_H
