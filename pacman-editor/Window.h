#ifndef Window_h
#define Window_h

class Window {
public:
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual sf::Vector2f getSize() = 0;
    virtual sf::Vector2f getPosition() = 0;
    virtual void setSize(sf::Vector2f) = 0;
    virtual void setPosition(sf::Vector2f) = 0;
};

class WinShape : public Window {
public:
    WinShape(sf::Vector2f size, sf::Color color);
    WinShape(sf::Vector2f size, sf::Vector2f position, sf::Color color);

    void draw(sf::RenderWindow& window);
    sf::Vector2f getSize();
    sf::Vector2f getPosition();
    void setSize(sf::Vector2f);
    void setPosition(sf::Vector2f);

private:
    sf::RectangleShape Shape;
};

class SelectionBox : public WinShape {
public:
    SelectionBox(sf::Vector2f size, sf::Vector2f position, sf::Color color);

    sf::Vector2i spriteSelected; // выбраный спрайт
    sf::Vector2i selectionPos; // нужно для корректного отображения selectionBox
};

SelectionBox::SelectionBox(sf::Vector2f size, sf::Vector2f position, sf::Color color) :
    WinShape(size, position, color),
    spriteSelected(0, 0),
    selectionPos(2, 2)
    {}

class Tileset {
public:
    Tileset(const char* picture, sf::Vector2f position);

    void draw(sf::RenderWindow& window);
    sf::Vector2u getTextureSize();
    void setTextureRect(sf::IntRect rect);
    void setPosition(sf::Vector2f position);
    void TextureCutting(WinShape tilesetShape);

    bool isLargerX;
    bool isLargerY;
private:
    sf::Texture texture;
    sf::Sprite sprite;
};

class Grid {
public:
    Grid(int width, int height, int thick);
    void draw(sf::RenderWindow& window);
private:
    sf::RectangleShape line;
    int height;
    int width;
    int thick;
};

#endif
