#ifndef Tile_h
#define Tile_h

class Tile {
public:
    int sx, sy;
    bool isCollidable;
    char id;

    Tile();
    Tile(int sx, int sy, bool isCollidable, char _id);
    Tile(int x, int y, int sx, int sy, bool isCollidable);

private:
    int x, y;
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
