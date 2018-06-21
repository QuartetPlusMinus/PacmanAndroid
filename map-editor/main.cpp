#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include "Window.h"
#include "Button.h"
#include "Tile.h"

using namespace sf; // TODO: remove using namespace

const int mapWidth = 480; // TODO: make upcase
//const int MAP_WIDTH = 480;

const int mapHeight = 768;
const int sideMenuWidth = 300;

RenderWindow window(VideoMode(mapWidth + sideMenuWidth, mapHeight), "MapEditor");

Vector2i startingMousePos(0, 0);
Vector2i startingOffset(0, 0);

std::vector<Tile> map; // TODO: change to 2d array
std::vector<Hero> heroPos;

bool isMoving = false;
bool isDrawing = false;

enum toolType { // TODO: Up first letter
    drawing = 1, // TODO: upcase
    removing
} tool;

enum heroType { // TODO: Up first letter
    empty, // TODO: upcase
    pacman,
    ghost
} hero;

void saveMap();
void update();

// TODO: replace file names to constants
// TODO: remove all varibles of global area
// TODO: make contants
//Color GRAY_COLOR(100,100,100);


ScrollingField mapSc(0, 0, mapWidth, mapHeight, 0, 0);

ScrollingField tilesetSc(mapWidth + 20, mapHeight - 400, 120, 380, 0, 0);
WinShape tilesetShape(Vector2f(tilesetSc.width, tilesetSc.height), Vector2f(tilesetSc.x, tilesetSc.y), Color(100, 100, 100));
Tileset tileset("tileset.png", Vector2f(tilesetSc.x, tilesetSc.y));
Tileset tile("tileset.png", Vector2f(0, 0));

Tileset pacIcon("draw.png", Vector2f(0, 0));
Tileset ghostIcon("wall.png", Vector2f(0, 0));

ScrollingField tilesetScWall(mapWidth + 20 + tilesetSc.width + 20, mapHeight - 400, 120, 380, 0, 0);
WinShape tilesetShapeWall(Vector2f(tilesetScWall.width, tilesetScWall.height), Vector2f(tilesetScWall.x, tilesetScWall.y), Color(100, 100, 100));
Tileset tilesetWall("tileset.png", Vector2f(tilesetScWall.x, tilesetScWall.y));
Tileset tileWall("tileset.png", Vector2f(0, 0));

WinShape sideMenu(Vector2f(sideMenuWidth, mapHeight), Vector2f(mapWidth, 0), Color(120, 120, 120));
WinShape collidableBox(Vector2f(32, 32), Color(0, 0, 255, 75));
SelectionBox selectionBox(Vector2f(32, 32), Vector2f(tilesetSc.x, tilesetSc.y), Color(0, 0, 255, 75));

NavMenu navbar(mapWidth, 0);
ToolMenu toolbar(mapWidth + 20, 80);
HeroMenu herobar(mapWidth + 20, 210);

Grid grid(mapWidth, mapHeight, 1);

RectangleShape rectangle;

int main()
{
    tileset.TextureCutting(tilesetShape);
    tilesetWall.TextureCutting(tilesetShape);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if(event.type == Event::MouseButtonPressed) {
                // TODO: clear code

                if(Keyboard::isKeyPressed(Keyboard::Space)) {
                    isMoving = true;
                    startingMousePos = Vector2i(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
                    if(Mouse::getPosition(window).x < mapWidth) {
                        startingOffset = Vector2i(mapSc.offsetX, mapSc.offsetY);
                    } else if(Mouse::getPosition(window).x > tilesetSc.x && Mouse::getPosition(window).x < tilesetSc.x + tilesetSc.width &&
                              Mouse::getPosition(window).y > tilesetSc.y && Mouse::getPosition(window).y < tilesetSc.y + tilesetSc.height) {
                        startingOffset = Vector2i(tilesetSc.offsetX, tilesetSc.offsetY);
                    } else if(Mouse::getPosition(window).x > tilesetScWall.x && Mouse::getPosition(window).x < tilesetScWall.x + tilesetScWall.width &&
                              Mouse::getPosition(window).y > tilesetScWall.y && Mouse::getPosition(window).y < tilesetScWall.y + tilesetScWall.height) {
                        startingOffset = Vector2i(tilesetScWall.offsetX, tilesetScWall.offsetY);
                    }
                } else if(Mouse::getPosition(window).x > tilesetSc.x && Mouse::getPosition(window).x < tilesetSc.x + tilesetSc.width &&
                          Mouse::getPosition(window).y > tilesetSc.y && Mouse::getPosition(window).y < tilesetSc.y + tilesetSc.height) {
                    selectionBox.spriteSelected.x = (Mouse::getPosition(window).x - tilesetSc.x + tilesetSc.offsetX) / 32;
                    selectionBox.spriteSelected.y = (Mouse::getPosition(window).y - tilesetSc.y + tilesetSc.offsetY) / 32;
                    selectionBox.isWall = false;
                } else if(Mouse::getPosition(window).x > tilesetScWall.x && Mouse::getPosition(window).x < tilesetScWall.x + tilesetScWall.width &&
                          Mouse::getPosition(window).y > tilesetScWall.y && Mouse::getPosition(window).y < tilesetScWall.y + tilesetScWall.height) {
                    selectionBox.spriteSelected.x = (Mouse::getPosition(window).x - tilesetScWall.x + tilesetScWall.offsetX) / 32;
                    selectionBox.spriteSelected.y = (Mouse::getPosition(window).y - tilesetScWall.y + tilesetScWall.offsetY) / 32;
                    selectionBox.isWall = true;
                } else if(Mouse::getPosition(window).x < mapWidth) {
                    isDrawing = true;
                }
            } else if(event.type == Event::MouseButtonReleased) {
                isMoving = false;
                isDrawing = false;
            }
        }

        navbar.SelectedItem(navbar.selectedItemIndex, navbar.selected);

        update();

        window.clear(Color(50, 50, 50));

        for(int i = 0; i < map.size(); i++) {
            if(map.at(i).isCollidable) {
                tile.setTextureRect(IntRect(map.at(i).sx * 32, map.at(i).sy * 32, 32, 32)); // TODO: make constants
                tile.setPosition(Vector2f(map.at(i).x * 32 + mapSc.offsetX, map.at(i).y * 32 + mapSc.offsetY));
                tile.draw(window);
            } else {
                tileWall.setTextureRect(IntRect(map.at(i).sx * 32, map.at(i).sy * 32, 32, 32));
                tileWall.setPosition(Vector2f(map.at(i).x * 32 + mapSc.offsetX, map.at(i).y * 32 + mapSc.offsetY));
                tileWall.draw(window);
            }
        }

        if(hero != empty) {
            for(int i = 0; i < heroPos.size(); i++) {
                if(heroPos.at(i).isGhost) {
                    ghostIcon.setPosition(Vector2f(heroPos.at(i).x * 32 + mapSc.offsetX, heroPos.at(i).y * 32 + mapSc.offsetY));
                    ghostIcon.draw(window);
                } else {
                    pacIcon.setPosition(Vector2f(heroPos.at(i).x * 32 + mapSc.offsetX, heroPos.at(i).y * 32 + mapSc.offsetY));
                    pacIcon.draw(window);
                }
            }
        }

        grid.draw(window);
        sideMenu.draw(window);
        tilesetShape.draw(window);
        tilesetShapeWall.draw(window);
        tileset.draw(window);
        tilesetWall.draw(window);
        if(selectionBox.selectionPos.x != 0 && selectionBox.selectionPos.y != 0) {
            selectionBox.draw(window);
        }

        navbar.draw(window);
        toolbar.draw(window);
        herobar.draw(window);

        window.display();
    }

    return 0;
}

//-----------------------------

// TODO: remove
template <class T>
void sort(std::vector<Tile>& map, const T& func) {
    if(map.size() < 1) {
        return;
    }
    for(int i = 0; i < map.size() - 1; ++i) {
        for(int j = 0; j < map.size() - i - 1; ++j) {
            if(func(map[j], map[j + 1])) {
                std::swap(map[j], map[j + 1]);
            }
        }
    }
}

// TODO: make class Map and remove there
void saveMap() {
    sort(map,
        [](const Tile& first, const Tile& second) {
            return (first.y > second.y);
        }
    );
    sort(map,
        [](const Tile& first, const Tile& second) {
            return (first.x > second.x && first.y == second.y);
        }
    );

    std::ofstream out;
    out.open("out.txt", std::ios_base::trunc);
    for(int i = 0; i < map.size(); i++) {
        out << map.at(i).x << " "
            << map.at(i).y << " "
            << map.at(i).sx << " "
            << map.at(i).sy << " "
            << map.at(i).isCollidable;

        if(i != map.size() - 1) {
            out << std::endl;
        }
    }
    out.close();
}

void update()
{
    navbar.whichItemSelected(window);
    if(navbar.selected) {
        navbar.SelectedItem(navbar.selectedItemIndex, navbar.selected);
        if(Mouse::isButtonPressed(Mouse::Left)) {
            switch(navbar.selectedItemIndex) {
                case 0:
                    saveMap();
                    break;
                case 1:
                    map.clear();
                    break;
                case 2:
                    window.close();
                    break;
            }
        }
        navbar.selected = false;
    }

    toolbar.whichItemSelected(window);
    if(toolbar.selected) {
        if(Mouse::isButtonPressed(Mouse::Left)) {
            toolbar.SelectedItem(toolbar.selectedItemIndex, toolbar.selected);
            switch(toolbar.selectedItemIndex) {
                case 0:
                    tool = drawing;
                    break;
                case 1:
                    tool = removing;
                    break;
            }
        }
        toolbar.selected = false;
    }

    herobar.whichItemSelected(window);
    if(herobar.selected) {
        if(Mouse::isButtonPressed(Mouse::Left)) {
            herobar.SelectedItem(herobar.selectedItemIndex, herobar.selected);
            switch(herobar.selectedItemIndex) {
                case 0:
                    hero = pacman;
                    break;
                case 1:
                    hero = ghost;
                    break;
            }
        }
        if(Mouse::isButtonPressed(Mouse::Right)) {
            herobar.selected = false;
            hero = empty;
            herobar.SelectedItem(herobar.selectedItemIndex, herobar.selected);
        }
    }

    if(Keyboard::isKeyPressed(Keyboard::Space)) {
        if(isMoving) {
            if(Mouse::getPosition(window).x > tilesetSc.x && Mouse::getPosition(window).x < tilesetSc.x + tilesetSc.width &&
               Mouse::getPosition(window).y > tilesetSc.y && Mouse::getPosition(window).y < tilesetSc.y + tilesetSc.height) {

                if(tileset.isLargerX) {
                    tilesetSc.offsetX = startingOffset.x + startingMousePos.x - Mouse::getPosition(window).x;
                }
                if(tileset.isLargerY) {
                    tilesetSc.offsetY = startingOffset.y + startingMousePos.y - Mouse::getPosition(window).y;
                }

                if(tilesetSc.offsetX < 0) {
                    tilesetSc.offsetX = 0;
                }
                if(tilesetSc.offsetY < 0) {
                    tilesetSc.offsetY = 0;
                }
                if(tilesetSc.offsetX > tileset.getTextureSize().x - tilesetSc.width) {
                    tilesetSc.offsetX = tileset.getTextureSize().x - tilesetSc.width;
                }
                if(tilesetSc.offsetY > tileset.getTextureSize().y - tilesetSc.height) {
                    tilesetSc.offsetY = tileset.getTextureSize().y - tilesetSc.height;
                }
            } else if(Mouse::getPosition(window).x > tilesetScWall.x && Mouse::getPosition(window).x < tilesetScWall.x + tilesetScWall.width
                   && Mouse::getPosition(window).y > tilesetScWall.y && Mouse::getPosition(window).y < tilesetScWall.y + tilesetScWall.height) {
                if(tilesetWall.isLargerX) {
                    tilesetScWall.offsetX = startingOffset.x + startingMousePos.x - Mouse::getPosition(window).x;
                }
                if(tilesetWall.isLargerY) {
                    tilesetScWall.offsetY = startingOffset.y + startingMousePos.y - Mouse::getPosition(window).y;
                }

                if(tilesetScWall.offsetX < 0) {
                    tilesetScWall.offsetX = 0;
                }
                if(tilesetScWall.offsetY < 0) {
                    tilesetScWall.offsetY = 0;
                }
                if(tilesetScWall.offsetX > tilesetWall.getTextureSize().x - tilesetScWall.width) {
                    tilesetScWall.offsetX = tilesetWall.getTextureSize().x - tilesetScWall.width;
                }
                if(tilesetScWall.offsetY > tilesetWall.getTextureSize().y - tilesetScWall.height) {
                    tilesetScWall.offsetY = tilesetWall.getTextureSize().y - tilesetScWall.height;
                }
            }
        } else {
            startingOffset.x = mapSc.offsetX;
            startingOffset.y = mapSc.offsetY;
        }
    } else {
        if(isDrawing
        && Mouse::getPosition(window).x < mapWidth && Mouse::getPosition(window).x >= 0
        && Mouse::getPosition(window).y < mapHeight && Mouse::getPosition(window).y >= 0) {
            if(tool == drawing && hero == empty) {
                // bool isEmpty = false;
                for(int i = 0; i < map.size(); i++) {
                    if(map.at(i).x == (Mouse::getPosition(window).x - mapSc.offsetX) / 32
                    && map.at(i).y == (Mouse::getPosition(window).y - mapSc.offsetY) / 32) {
                       // isEmpty = true;
                       map.erase(map.begin() + i);
                   }
                }
                if(!selectionBox.isWall) {
                    map.push_back(Tile((Mouse::getPosition(window).x - mapSc.offsetX) / 32,
                        (Mouse::getPosition(window).y - mapSc.offsetY) / 32,
                        selectionBox.spriteSelected.x, selectionBox.spriteSelected.y, false)
                    );
                } else {
                    map.push_back(Tile((Mouse::getPosition(window).x - mapSc.offsetX) / 32,
                        (Mouse::getPosition(window).y - mapSc.offsetY) / 32,
                        selectionBox.spriteSelected.x, selectionBox.spriteSelected.y, true)
                    );
                }
            } else if(tool == removing && hero == empty) {
                for(int i = 0; i < map.size(); i++) {
                    if(map.at(i).x == (Mouse::getPosition(window).x - mapSc.offsetX) / 32
                    && map.at(i).y == (Mouse::getPosition(window).y - mapSc.offsetY) / 32) {
                        map.erase(map.begin() + i);
                    }
                }
            } else if(tool == drawing && hero == pacman) {
                heroPos.push_back(Hero((Mouse::getPosition(window).x - mapSc.offsetX) / 32,
                    (Mouse::getPosition(window).y - mapSc.offsetY) / 32, false)
                );
            } else if(tool == drawing && hero == ghost) {
                heroPos.push_back(Hero((Mouse::getPosition(window).x - mapSc.offsetX) / 32,
                    (Mouse::getPosition(window).y - mapSc.offsetY) / 32, true)
                );
            } else if(tool == removing && hero != empty) {
                for(int i = 0; i < heroPos.size(); i++) {
                    if(heroPos.at(i).x == (Mouse::getPosition(window).x - mapSc.offsetX) / 32
                    && heroPos.at(i).y == (Mouse::getPosition(window).y - mapSc.offsetY) / 32) {
                        heroPos.erase(heroPos.begin() + i);
                    }
                }
            }
        }
    }

    // корректное отображение картинки при скролле
    if(tileset.isLargerX && tileset.isLargerY) {
        tileset.setTextureRect(IntRect(tilesetSc.offsetX, tilesetSc.offsetY, tilesetSc.width, tilesetSc.height));
    } else if(tileset.isLargerX && !tileset.isLargerY) {
        tileset.setTextureRect(IntRect(tilesetSc.offsetX, 0, tilesetSc.width, tileset.getTextureSize().y));
    } else if(!tileset.isLargerX && tileset.isLargerY) {
        tileset.setTextureRect(IntRect(0, tilesetSc.offsetY, tileset.getTextureSize().x, tilesetSc.height));
    } else if(!tileset.isLargerX && !tileset.isLargerY) {
        tileset.setTextureRect(IntRect(0, 0, tileset.getTextureSize().x, tileset.getTextureSize().y));
    }

    if(tilesetWall.isLargerX && tilesetWall.isLargerY) {
        tilesetWall.setTextureRect(IntRect(tilesetScWall.offsetX, tilesetScWall.offsetY, tilesetScWall.width, tilesetScWall.height));
    } else if(tilesetWall.isLargerX && !tilesetWall.isLargerY) {
        tilesetWall.setTextureRect(IntRect(tilesetScWall.offsetX, 0, tilesetScWall.width, tilesetWall.getTextureSize().y));
    } else if(!tilesetWall.isLargerX && tilesetWall.isLargerY) {
        tilesetWall.setTextureRect(IntRect(0, tilesetScWall.offsetY, tilesetWall.getTextureSize().x, tilesetScWall.height));
    } else if(!tilesetWall.isLargerX && !tilesetWall.isLargerY) {
        tilesetWall.setTextureRect(IntRect(0, 0, tilesetWall.getTextureSize().x, tilesetWall.getTextureSize().y));
    }

    if(Mouse::getPosition(window).x > tilesetSc.x && Mouse::getPosition(window).x < tilesetSc.x + tilesetSc.width
    && Mouse::getPosition(window).y > tilesetSc.y && Mouse::getPosition(window).y < tilesetSc.y + tilesetSc.height
    && Mouse::isButtonPressed(Mouse::Left)) {
        selectionBox.setPosition(Vector2f(tilesetSc.x + selectionBox.spriteSelected.x * 32 - tilesetSc.offsetX, tilesetSc.y + selectionBox.spriteSelected.y * 32 - tilesetSc.offsetY));

        // корректное отображение выбраной плитки в tilesetSc
        if(selectionBox.getPosition().x < tilesetSc.x && selectionBox.getPosition().x > tilesetSc.x - 32) {
            selectionBox.selectionPos.x = 1;
        }
        if(selectionBox.getPosition().x > tilesetSc.x + tilesetSc.width - 32 && selectionBox.getPosition().x < tilesetSc.x + tilesetSc.width + 32) {
            selectionBox.selectionPos.x = 3;
        }
        if(selectionBox.getPosition().y < tilesetSc.y && selectionBox.getPosition().y > tilesetSc.y - 32) {
            selectionBox.selectionPos.y = 1;
        }
        if(selectionBox.getPosition().y > tilesetSc.y + tilesetSc.height - 32 && selectionBox.getPosition().y < tilesetSc.y + tilesetSc.height + 32) {
            selectionBox.selectionPos.y = 3;
        }
        if(selectionBox.getPosition().x > tilesetSc.x && selectionBox.getPosition().x < tilesetSc.x + tilesetSc.width - 32) {
            selectionBox.selectionPos.x = 2;
        }
        if(selectionBox.getPosition().y > tilesetSc.y && selectionBox.getPosition().y < tilesetSc.y + tilesetSc.height - 32) {
            selectionBox.selectionPos.y = 2;
        }
        if(selectionBox.getPosition().x <= tilesetSc.x - 32 || selectionBox.getPosition().x >= tilesetSc.x + tilesetSc.width) {
            selectionBox.selectionPos.x = 0;
        }
        if(selectionBox.getPosition().y <= tilesetSc.y - 32 || selectionBox.getPosition().y >= tilesetSc.y + tilesetSc.height) {
            selectionBox.selectionPos.y = 0;
        }

        if(selectionBox.selectionPos.x == 1) {
            selectionBox.setSize(Vector2f(32 - tilesetSc.x + selectionBox.getPosition().x, selectionBox.getSize().y));
            selectionBox.setPosition(Vector2f(tilesetSc.x, selectionBox.getPosition().y));
        } else if(selectionBox.selectionPos.x == 3) {
            selectionBox.setSize(Vector2f(tilesetSc.x + tilesetSc.width - selectionBox.getPosition().x, selectionBox.getSize().y));
            selectionBox.setPosition(Vector2f(tilesetSc.x + tilesetSc.width - selectionBox.getSize().x, selectionBox.getPosition().y));
        }
        if(selectionBox.selectionPos.y == 1) {
            selectionBox.setSize(Vector2f(selectionBox.getSize().x, 32 - tilesetSc.y + selectionBox.getPosition().y));
            selectionBox.setPosition(Vector2f(selectionBox.getPosition().x, tilesetSc.y));
        } else if(selectionBox.selectionPos.y == 3) {
            selectionBox.setSize(Vector2f(selectionBox.getSize().x, tilesetSc.y + tilesetSc.height - selectionBox.getPosition().y));
            selectionBox.setPosition(Vector2f(selectionBox.getPosition().x, tilesetSc.y + tilesetSc.height - selectionBox.getSize().y));
        }
        if(selectionBox.selectionPos.x == 2) {
            selectionBox.setSize(Vector2f(32, selectionBox.getSize().y));
        }
        if(selectionBox.selectionPos.y == 2) {
            selectionBox.setSize(Vector2f(selectionBox.getSize().x, 32));
        }
    } else if(Mouse::getPosition(window).x > tilesetScWall.x && Mouse::getPosition(window).x < tilesetScWall.x + tilesetScWall.width
        && Mouse::getPosition(window).y > tilesetScWall.y && Mouse::getPosition(window).y < tilesetScWall.y + tilesetScWall.height
        && Mouse::isButtonPressed(Mouse::Left)) {
            selectionBox.setPosition(Vector2f(tilesetScWall.x + selectionBox.spriteSelected.x * 32 - tilesetScWall.offsetX, tilesetScWall.y + selectionBox.spriteSelected.y * 32 - tilesetScWall.offsetY));

            if(selectionBox.getPosition().x < tilesetScWall.x && selectionBox.getPosition().x > tilesetScWall.x - 32) {
                selectionBox.selectionPos.x = 1;
            }
            if(selectionBox.getPosition().x > tilesetScWall.x + tilesetScWall.width - 32 && selectionBox.getPosition().x < tilesetScWall.x + tilesetScWall.width + 32) {
                selectionBox.selectionPos.x = 3;
            }
            if(selectionBox.getPosition().y < tilesetScWall.y && selectionBox.getPosition().y > tilesetScWall.y - 32) {
                selectionBox.selectionPos.y = 1;
            }
            if(selectionBox.getPosition().y > tilesetScWall.y + tilesetScWall.height - 32 && selectionBox.getPosition().y < tilesetScWall.y + tilesetScWall.height + 32) {
                selectionBox.selectionPos.y = 3;
            }
            if(selectionBox.getPosition().x > tilesetScWall.x && selectionBox.getPosition().x < tilesetScWall.x + tilesetScWall.width - 32) {
                selectionBox.selectionPos.x = 2;
            }
            if(selectionBox.getPosition().y > tilesetScWall.y && selectionBox.getPosition().y < tilesetScWall.y + tilesetScWall.height - 32) {
                selectionBox.selectionPos.y = 2;
            }
            if(selectionBox.getPosition().x <= tilesetScWall.x - 32 || selectionBox.getPosition().x >= tilesetScWall.x + tilesetScWall.width) {
                selectionBox.selectionPos.x = 0;
            }
            if(selectionBox.getPosition().y <= tilesetScWall.y - 32 || selectionBox.getPosition().y >= tilesetScWall.y + tilesetScWall.height) {
                selectionBox.selectionPos.y = 0;
            }

            if(selectionBox.selectionPos.x == 1) {
                selectionBox.setSize(Vector2f(32 - tilesetScWall.x + selectionBox.getPosition().x, selectionBox.getSize().y));
                selectionBox.setPosition(Vector2f(tilesetScWall.x, selectionBox.getPosition().y));
            } else if(selectionBox.selectionPos.x == 3) {
                selectionBox.setSize(Vector2f(tilesetScWall.x + tilesetScWall.width - selectionBox.getPosition().x, selectionBox.getSize().y));
                selectionBox.setPosition(Vector2f(tilesetScWall.x + tilesetScWall.width - selectionBox.getSize().x, selectionBox.getPosition().y));
            }
            if(selectionBox.selectionPos.y == 1) {
                selectionBox.setSize(Vector2f(selectionBox.getSize().x, 32 - tilesetScWall.y + selectionBox.getPosition().y));
                selectionBox.setPosition(Vector2f(selectionBox.getPosition().x, tilesetScWall.y));
            } else if(selectionBox.selectionPos.y == 3) {
                selectionBox.setSize(Vector2f(selectionBox.getSize().x, tilesetScWall.y + tilesetScWall.height - selectionBox.getPosition().y));
                selectionBox.setPosition(Vector2f(selectionBox.getPosition().x, tilesetScWall.y + tilesetScWall.height - selectionBox.getSize().y));
            }
            if(selectionBox.selectionPos.x == 2) {
                selectionBox.setSize(Vector2f(32, selectionBox.getSize().y));
            }
            if(selectionBox.selectionPos.y == 2) {
                selectionBox.setSize(Vector2f(selectionBox.getSize().x, 32));
            }
        }
}
//-----------------------------
