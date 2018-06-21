#ifndef Tile_h
#define Tile_h

//TODO: make private or const propertys

class Tile {
public:
    int x, y;
    int sx, sy;
    bool isCollidable;

    Tile(int x, int y, int sx, int sy, bool isCollidable);
    Tile();
};

class ScrollingField {
public:
    int x, y;
    int width, height;
    int offsetX, offsetY;

    ScrollingField(int x, int y, int w, int h, int offsetX, int offsetY);
};

class Hero {
public:
    int x, y;
    bool isGhost;

    Hero(int x, int y, bool isGhost);
};

#endif
