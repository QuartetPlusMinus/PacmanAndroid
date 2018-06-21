//
// Created by views on 08.06.18.
//

#ifndef ANDROID_CLIENT_BACKGROUND_H
#define ANDROID_CLIENT_BACKGROUND_H

#include <GLES2/gl2.h>
#include "IDrawable.h"
#include "libodraw/libodraw.h"

class Background : public IDrawable {
public:
    Background();

    void setTexture(std::shared_ptr<od::Texture> texture);

    void init() final;

    void draw() final;

private:
    od::Sprite sprite;
};

#endif //ANDROID_CLIENT_BACKGROUND_H
