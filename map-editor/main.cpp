#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include "Window.h"
#include "Button.h"
#include "Tile.h"

using namespace sf;

const int mapWidth using namespace sf;

const int MAP_WIDTH = 480;
const int MAP_HEIGHT = 768;
const int SIDE_MENU_WIDTH = 300;
const int BLOCK_SIZE = 32;

RenderWindow window(VideoMode(MAP_WIDTH + SIDE_MENU_WIDTH, MAP_HEIGHT), "MapEditor");

Tile map[MAP_WIDTH / BLOCK_SIZE][MAP_HEIGHT / BLOCK_SIZE];

enum ToolType {
    DRAWING = 1,
    REMOVING
};

enum HeroType {
    EMPTY,
    PACMAN,
    GHOST
};

void update(std::vector<Hero> heroPos, ToolType tool, HeroType hero, sf::Vector2i startingMousePos, sf::Vector2i startingOffset, bool isMoving, bool isDrawing, NavMenu navbar, ToolMenu toolbar, HeroMenu herobar, ScrollingField mapSc, ScrollingField tilesetSc, ScrollingField tilesetScWall, Tileset tileset, Tileset tilesetWall, SelectionBox selectionBox);

int main()
{
    Vector2i startingMousePos(0, 0);
    Vector2i startingOffset(0, 0);

    bool isMoving = false;
    bool isDrawing = false;

    ToolType tool;
    HeroType hero;

    std::vector<Hero> heroPos;

    ScrollingField mapSc(0, 0, MAP_WIDTH, MAP_HEIGHT, 0, 0);

    ScrollingField tilesetSc(MAP_WIDTH + 20, MAP_HEIGHT - 400, 120, 380, 0, 0);
    WinShape tilesetShape(Vector2f(tilesetSc.width, tilesetSc.height), Vector2f(tilesetSc.x, tilesetSc.y), Color(100, 100, 100));
    Tileset tileset("tileset.png", Vector2f(tilesetSc.x, tilesetSc.y));
    Tileset tile("tileset.png", Vector2f(0, 0));

    Tileset pacIcon("draw.png", Vector2f(0, 0));
    Tileset ghostIcon("wall.png", Vector2f(0, 0));

    ScrollingField tilesetScWall(MAP_WIDTH + 20 + tilesetSc.width + 20, MAP_HEIGHT - 400, 120, 380, 0, 0);
    WinShape tilesetShapeWall(Vector2f(tilesetScWall.width, tilesetScWall.height), Vector2f(tilesetScWall.x, tilesetScWall.y), Color(100, 100, 100));
    Tileset tilesetWall("tileset.png", Vector2f(tilesetScWall.x, tilesetScWall.y));
    Tileset tileWall("tileset.png", Vector2f(0, 0));

    WinShape sideMenu(Vector2f(SIDE_MENU_WIDTH, MAP_HEIGHT), Vector2f(MAP_WIDTH, 0), Color(120, 120, 120));
    WinShape collidableBox(Vector2f(BLOCK_SIZE, BLOCK_SIZE), Color(0, 0, 255, 75));
    SelectionBox selectionBox(Vector2f(BLOCK_SIZE, BLOCK_SIZE), Vector2f(tilesetSc.x, tilesetSc.y), Color(0, 0, 255, 75));

    NavMenu navbar(MAP_WIDTH, 0);
    ToolMenu toolbar(MAP_WIDTH + 20, 80);
    HeroMenu herobar(MAP_WIDTH + 20, 210);

    Grid grid(MAP_WIDTH, MAP_HEIGHT, 1);

    for(int i = 0; i < MAP_WIDTH / BLOCK_SIZE; i++) {
        for(int j = 0; j < MAP_HEIGHT / BLOCK_SIZE; j++) {
            map[i][j] = Tile(0,0,0,0,0);
        }
    }

    tileset.TextureCutting(tilesetShape);
    tilesetWall.TextureCutting(tilesetShape);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if(event.type == Event::MouseButtonPressed) {
                if(Keyboard::isKeyPressed(Keyboard::Space)) {
                    isMoving = true;
                    startingMousePos = Vector2i(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
                    if(Mouse::getPosition(window).x < MAP_WIDTH) {
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
                    selectionBox.spriteSelected.x = (Mouse::getPosition(window).x - tilesetSc.x + tilesetSc.offsetX) / BLOCK_SIZE;
                    selectionBox.spriteSelected.y = (Mouse::getPosition(window).y - tilesetSc.y + tilesetSc.offsetY) / BLOCK_SIZE;
                    selectionBox.isWall = false;
                } else if(Mouse::getPosition(window).x > tilesetScWall.x && Mouse::getPosition(window).x < tilesetScWall.x + tilesetScWall.width &&
                          Mouse::getPosition(window).y > tilesetScWall.y && Mouse::getPosition(window).y < tilesetScWall.y + tilesetScWall.height) {
                    selectionBox.spriteSelected.x = (Mouse::getPosition(window).x - tilesetScWall.x + tilesetScWall.offsetX) / BLOCK_SIZE;
                    selectionBox.spriteSelected.y = (Mouse::getPosition(window).y - tilesetScWall.y + tilesetScWall.offsetY) / BLOCK_SIZE;
                    selectionBox.isWall = true;
                } else if(Mouse::getPosition(window).x < MAP_WIDTH) {
                    isDrawing = true;
                }
            } else if(event.type == Event::MouseButtonReleased) {
                isMoving = false;
                isDrawing = false;
            }
        }

        navbar.SelectedItem(navbar.selectedItemIndex, navbar.selected);

        // update();
        update(heroPos, tool, hero, startingMousePos, startingOffset, isMoving, isDrawing, navbar, toolbar, herobar, mapSc, tilesetSc, tilesetScWall, tileset, tilesetWall, selectionBox);

        window.clear(Color(50, 50, 50));

        for(int i = 0; i < MAP_WIDTH / BLOCK_SIZE; i++) {
            for(int j = 0; j < MAP_HEIGHT / BLOCK_SIZE; j++) {
                if(map[i][j].id == 0) {
                    continue;
                }
                if(map[i][j].isCollidable) {
                    tile.setTextureRect(IntRect(map[i][j].sx * BLOCK_SIZE, map[i][j].sy * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE));
                    tile.setPosition(Vector2f(i * BLOCK_SIZE + mapSc.offsetX, j * BLOCK_SIZE + mapSc.offsetY));
                    tile.draw(window);
                } else {
                    tileWall.setTextureRect(IntRect(map[i][j].sx * BLOCK_SIZE,map[i][j].sy * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE));
                    tileWall.setPosition(Vector2f(i * BLOCK_SIZE + mapSc.offsetX, j * BLOCK_SIZE + mapSc.offsetY));
                    tileWall.draw(window);
                }
            }
        }

        if(hero != EMPTY) {
            for(int i = 0; i < heroPos.size(); i++) {
                if(heroPos.at(i).isGhost) {
                    ghostIcon.setPosition(Vector2f(heroPos.at(i).x * BLOCK_SIZE + mapSc.offsetX, heroPos.at(i).y * BLOCK_SIZE + mapSc.offsetY));
                    ghostIcon.draw(window);
                } else {
                    pacIcon.setPosition(Vector2f(heroPos.at(i).x * BLOCK_SIZE + mapSc.offsetX, heroPos.at(i).y * BLOCK_SIZE + mapSc.offsetY));
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
// template <class T>
// void sort(std::vector<Tile>& map, const T& func) {
//     if(map.size() < 1) {
//         return;
//     }
//     for(int i = 0; i < map.size() - 1; ++i) {
//         for(int j = 0; j < map.size() - i - 1; ++j) {
//             if(func(map[j], map[j + 1])) {
//                 std::swap(map[j], map[j + 1]);
//             }
//         }
//     }
// }
//
// void saveMap() {
//     sort(map,
//         [](const Tile& first, const Tile& second) {
//             return (first.y > second.y);
//         }
//     );
//     sort(map,
//         [](const Tile& first, const Tile& second) {
//             return (first.x > second.x && first.y == second.y);
//         }
//     );
//
//     std::ofstream out;
//     out.open("out.txt", std::ios_base::trunc);
//     for(int i = 0; i < map.size(); i++) {
//         out << map.at(i).x << " "
//             << map.at(i).y << " "
//             << map.at(i).sx << " "
//             << map.at(i).sy << " "
//             << map.at(i).isCollidable;
//
//         if(i != map.size() - 1) {
//             out << std::endl;
//         }
//     }
//     out.close();
// }



// void update()
void update(std::vector<Hero> heroPos, ToolType tool, HeroType hero, sf::Vector2i startingMousePos, sf::Vector2i startingOffset, bool isMoving, bool isDrawing, NavMenu navbar, ToolMenu toolbar, HeroMenu herobar, ScrollingField mapSc, ScrollingField tilesetSc, ScrollingField tilesetScWall, Tileset tileset, Tileset tilesetWall, SelectionBox selectionBox)
{
    navbar.whichItemSelected(window);
    if(navbar.selected) {
        navbar.SelectedItem(navbar.selectedItemIndex, navbar.selected);
        if(Mouse::isButtonPressed(Mouse::Left)) {
            switch(navbar.selectedItemIndex) {
                case 0:
                    // saveMap();
                    break;
                case 1:
                    for(int i = 0; i < MAP_WIDTH / BLOCK_SIZE; i++) {
                        for(int j = 0; j < MAP_HEIGHT / BLOCK_SIZE; j++) {
                            map[i][j].id = 0;
                        }
                    }
                    heroPos.clear();
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
                    tool = DRAWING;
                    break;
                case 1:
                    tool = REMOVING;
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
                    hero = PACMAN;
                    break;
                case 1:
                    hero = GHOST;
                    break;
            }
        }
        if(Mouse::isButtonPressed(Mouse::Right)) {
            herobar.selected = false;
            hero = EMPTY;
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
        && Mouse::getPosition(window).x < MAP_WIDTH && Mouse::getPosition(window).x >= 0
        && Mouse::getPosition(window).y < MAP_HEIGHT && Mouse::getPosition(window).y >= 0) {
            if(tool == DRAWING && hero == EMPTY) {
                if(!selectionBox.isWall) {
                    char id = selectionBox.spriteSelected.x + selectionBox.spriteSelected.y * tilesetSc.width + 128;
                    map[(Mouse::getPosition(window).x - mapSc.offsetX) / BLOCK_SIZE][(Mouse::getPosition(window).y - mapSc.offsetY) / BLOCK_SIZE] = Tile(selectionBox.spriteSelected.x, selectionBox.spriteSelected.y, false, id);
                } else {
                    char id = selectionBox.spriteSelected.x + selectionBox.spriteSelected.y * tilesetSc.width + 1;
                    map[(Mouse::getPosition(window).x - mapSc.offsetX) / BLOCK_SIZE][(Mouse::getPosition(window).y - mapSc.offsetY) / BLOCK_SIZE] = Tile(selectionBox.spriteSelected.x, selectionBox.spriteSelected.y, false, id);
                }
            } else if(tool == REMOVING && hero == EMPTY) {
                map[(Mouse::getPosition(window).x - mapSc.offsetX) / BLOCK_SIZE][(Mouse::getPosition(window).y - mapSc.offsetY) / BLOCK_SIZE].id = 0;
            } else if(tool == DRAWING && hero == PACMAN) {
                heroPos.push_back(Hero((Mouse::getPosition(window).x - mapSc.offsetX) / BLOCK_SIZE,
                    (Mouse::getPosition(window).y - mapSc.offsetY) / BLOCK_SIZE, false)
                );
            } else if(tool == DRAWING && hero == GHOST) {
                heroPos.push_back(Hero((Mouse::getPosition(window).x - mapSc.offsetX) / BLOCK_SIZE,
                    (Mouse::getPosition(window).y - mapSc.offsetY) / BLOCK_SIZE, true)
                );
            } else if(tool == REMOVING && hero != EMPTY) {
                for(int i = 0; i < heroPos.size(); i++) {
                    if(heroPos.at(i).x == (Mouse::getPosition(window).x - mapSc.offsetX) / BLOCK_SIZE
                    && heroPos.at(i).y == (Mouse::getPosition(window).y - mapSc.offsetY) / BLOCK_SIZE) {
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
        selectionBox.setPosition(Vector2f(tilesetSc.x + selectionBox.spriteSelected.x * BLOCK_SIZE - tilesetSc.offsetX, tilesetSc.y + selectionBox.spriteSelected.y * BLOCK_SIZE - tilesetSc.offsetY));

        // корректное отображение выбраной плитки в tilesetSc
        if(selectionBox.getPosition().x < tilesetSc.x && selectionBox.getPosition().x > tilesetSc.x - BLOCK_SIZE) {
            selectionBox.selectionPos.x = 1;
        }
        if(selectionBox.getPosition().x > tilesetSc.x + tilesetSc.width - BLOCK_SIZE && selectionBox.getPosition().x < tilesetSc.x + tilesetSc.width + BLOCK_SIZE) {
            selectionBox.selectionPos.x = 3;
        }
        if(selectionBox.getPosition().y < tilesetSc.y && selectionBox.getPosition().y > tilesetSc.y - BLOCK_SIZE) {
            selectionBox.selectionPos.y = 1;
        }
        if(selectionBox.getPosition().y > tilesetSc.y + tilesetSc.height - BLOCK_SIZE && selectionBox.getPosition().y < tilesetSc.y + tilesetSc.height + BLOCK_SIZE) {
            selectionBox.selectionPos.y = 3;
        }
        if(selectionBox.getPosition().x > tilesetSc.x && selectionBox.getPosition().x < tilesetSc.x + tilesetSc.width - BLOCK_SIZE) {
            selectionBox.selectionPos.x = 2;
        }
        if(selectionBox.getPosition().y > tilesetSc.y && selectionBox.getPosition().y < tilesetSc.y + tilesetSc.height - BLOCK_SIZE) {
            selectionBox.selectionPos.y = 2;
        }
        if(selectionBox.getPosition().x <= tilesetSc.x - BLOCK_SIZE || selectionBox.getPosition().x >= tilesetSc.x + tilesetSc.width) {
            selectionBox.selectionPos.x = 0;
        }
        if(selectionBox.getPosition().y <= tilesetSc.y - BLOCK_SIZE || selectionBox.getPosition().y >= tilesetSc.y + tilesetSc.height) {
            selectionBox.selectionPos.y = 0;
        }

        if(selectionBox.selectionPos.x == 1) {
            selectionBox.setSize(Vector2f(BLOCK_SIZE - tilesetSc.x + selectionBox.getPosition().x, selectionBox.getSize().y));
            selectionBox.setPosition(Vector2f(tilesetSc.x, selectionBox.getPosition().y));
        } else if(selectionBox.selectionPos.x == 3) {
            selectionBox.setSize(Vector2f(tilesetSc.x + tilesetSc.width - selectionBox.getPosition().x, selectionBox.getSize().y));
            selectionBox.setPosition(Vector2f(tilesetSc.x + tilesetSc.width - selectionBox.getSize().x, selectionBox.getPosition().y));
        }
        if(selectionBox.selectionPos.y == 1) {
            selectionBox.setSize(Vector2f(selectionBox.getSize().x, BLOCK_SIZE - tilesetSc.y + selectionBox.getPosition().y));
            selectionBox.setPosition(Vector2f(selectionBox.getPosition().x, tilesetSc.y));
        } else if(selectionBox.selectionPos.y == 3) {
            selectionBox.setSize(Vector2f(selectionBox.getSize().x, tilesetSc.y + tilesetSc.height - selectionBox.getPosition().y));
            selectionBox.setPosition(Vector2f(selectionBox.getPosition().x, tilesetSc.y + tilesetSc.height - selectionBox.getSize().y));
        }
        if(selectionBox.selectionPos.x == 2) {
            selectionBox.setSize(Vector2f(BLOCK_SIZE, selectionBox.getSize().y));
        }
        if(selectionBox.selectionPos.y == 2) {
            selectionBox.setSize(Vector2f(selectionBox.getSize().x, BLOCK_SIZE));
        }
    } else if(Mouse::getPosition(window).x > tilesetScWall.x && Mouse::getPosition(window).x < tilesetScWall.x + tilesetScWall.width
        && Mouse::getPosition(window).y > tilesetScWall.y && Mouse::getPosition(window).y < tilesetScWall.y + tilesetScWall.height
        && Mouse::isButtonPressed(Mouse::Left)) {
            selectionBox.setPosition(Vector2f(tilesetScWall.x + selectionBox.spriteSelected.x * BLOCK_SIZE - tilesetScWall.offsetX, tilesetScWall.y + selectionBox.spriteSelected.y * BLOCK_SIZE - tilesetScWall.offsetY));

            if(selectionBox.getPosition().x < tilesetScWall.x && selectionBox.getPosition().x > tilesetScWall.x - BLOCK_SIZE) {
                selectionBox.selectionPos.x = 1;
            }
            if(selectionBox.getPosition().x > tilesetScWall.x + tilesetScWall.width - BLOCK_SIZE && selectionBox.getPosition().x < tilesetScWall.x + tilesetScWall.width + BLOCK_SIZE) {
                selectionBox.selectionPos.x = 3;
            }
            if(selectionBox.getPosition().y < tilesetScWall.y && selectionBox.getPosition().y > tilesetScWall.y - BLOCK_SIZE) {
                selectionBox.selectionPos.y = 1;
            }
            if(selectionBox.getPosition().y > tilesetScWall.y + tilesetScWall.height - BLOCK_SIZE && selectionBox.getPosition().y < tilesetScWall.y + tilesetScWall.height + BLOCK_SIZE) {
                selectionBox.selectionPos.y = 3;
            }
            if(selectionBox.getPosition().x > tilesetScWall.x && selectionBox.getPosition().x < tilesetScWall.x + tilesetScWall.width - BLOCK_SIZE) {
                selectionBox.selectionPos.x = 2;
            }
            if(selectionBox.getPosition().y > tilesetScWall.y && selectionBox.getPosition().y < tilesetScWall.y + tilesetScWall.height - BLOCK_SIZE) {
                selectionBox.selectionPos.y = 2;
            }
            if(selectionBox.getPosition().x <= tilesetScWall.x - BLOCK_SIZE || selectionBox.getPosition().x >= tilesetScWall.x + tilesetScWall.width) {
                selectionBox.selectionPos.x = 0;
            }
            if(selectionBox.getPosition().y <= tilesetScWall.y - BLOCK_SIZE || selectionBox.getPosition().y >= tilesetScWall.y + tilesetScWall.height) {
                selectionBox.selectionPos.y = 0;
            }

            if(selectionBox.selectionPos.x == 1) {
                selectionBox.setSize(Vector2f(BLOCK_SIZE - tilesetScWall.x + selectionBox.getPosition().x, selectionBox.getSize().y));
                selectionBox.setPosition(Vector2f(tilesetScWall.x, selectionBox.getPosition().y));
            } else if(selectionBox.selectionPos.x == 3) {
                selectionBox.setSize(Vector2f(tilesetScWall.x + tilesetScWall.width - selectionBox.getPosition().x, selectionBox.getSize().y));
                selectionBox.setPosition(Vector2f(tilesetScWall.x + tilesetScWall.width - selectionBox.getSize().x, selectionBox.getPosition().y));
            }
            if(selectionBox.selectionPos.y == 1) {
                selectionBox.setSize(Vector2f(selectionBox.getSize().x, BLOCK_SIZE - tilesetScWall.y + selectionBox.getPosition().y));
                selectionBox.setPosition(Vector2f(selectionBox.getPosition().x, tilesetScWall.y));
            } else if(selectionBox.selectionPos.y == 3) {
                selectionBox.setSize(Vector2f(selectionBox.getSize().x, tilesetScWall.y + tilesetScWall.height - selectionBox.getPosition().y));
                selectionBox.setPosition(Vector2f(selectionBox.getPosition().x, tilesetScWall.y + tilesetScWall.height - selectionBox.getSize().y));
            }
            if(selectionBox.selectionPos.x == 2) {
                selectionBox.setSize(Vector2f(BLOCK_SIZE, selectionBox.getSize().y));
            }
            if(selectionBox.selectionPos.y == 2) {
                selectionBox.setSize(Vector2f(selectionBox.getSize().x, BLOCK_SIZE));
            }
        }
}
//-----------------------------
