#include "Tile.h"

Tile::Tile(int _sx, int _sy, bool _isCollidable, char _id) :
    id(_id),
    sx(_sx),
    sy(_sy),
    isCollidable(_isCollidable)
    {}

Tile::Tile(int _x, int _y, int _sx, int _sy, bool _isCollidable) :
    x(_x),
    y(_y),
    sx(_sx),
    sy(_sy),
    isCollidable(_isCollidable),
    id(0)
    {}

Tile::Tile() :
    x(0),
    y(0),
    sx(0),
    sy(0),
    isCollidable(false),
    id(0)
    {}

ScrollingField::ScrollingField(int _x, int _y, int _w, int _h, int _offsetX, int _offsetY) :
    x(_x),
    y(_y),
    width(_w),
    height(_h),
    offsetX(_offsetX),
    offsetY(_offsetY)
    {}

Hero::Hero(int x, int y, bool isGhost) :
    x(x),
    y(y),
    isGhost(isGhost)
    {}
