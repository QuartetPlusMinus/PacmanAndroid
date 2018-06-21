//
// Created by views on 08.06.18.
//

#include "Background.h"

Background::Background() : sprite() {}

void Background::setTexture(std::shared_ptr<od::Texture> texture) {
    sprite.setTexture(texture);
}

void Background::init() {
    sprite.init();
}

void Background::draw() {
    sprite.draw();
}