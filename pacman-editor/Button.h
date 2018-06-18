#ifndef Button_h
#define Button_h

class Button {
public:
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual void SelectedItem(int selectedItemIndex, bool selected) = 0;

    int selectedItemIndex;
    bool selected;
};

class NavMenu : public Button{
public:
	NavMenu(int x, int y);

	void draw(sf::RenderWindow &window);
    void SelectedItem(int selectedItemIndex, bool selected);

    void whichItemSelected(sf::RenderWindow& window);
private:
	sf::Font font;
    sf::RectangleShape navbar;
    sf::Text menu[3];
};

class ToolMenu : public Button {
public:
    ToolMenu(int x, int y);

    void draw(sf::RenderWindow &window);
    void SelectedItem(int selectedItemIndex, bool selected);
    void whichItemSelected(sf::RenderWindow& window);
private:
    sf::Font font;
    sf::RectangleShape toolbar;
    sf::Text tools[4];
    sf::Texture texture[4];
    sf::Sprite icon[4];
};

#endif
