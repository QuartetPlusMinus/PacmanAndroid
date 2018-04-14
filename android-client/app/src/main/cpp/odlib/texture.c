//
// Created by viewsharp on 12.04.18.
//

#include "texture.h"
#include <stdlib.h>
#include <assert.h>

Texture create_texture(const char *src) {
    return (Texture){src};
}