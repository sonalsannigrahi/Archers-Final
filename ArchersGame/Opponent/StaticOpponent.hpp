#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class StaticOpponent{

private:

    sf::RenderWindow* window;

    std::vector<sf::Sprite> opponentSprites;
    sf::Sprite* opponent = new sf::Sprite;
    int winWidth, winHeight;

    bool alive = true;

    double timer;

public:

    StaticOpponent();

    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);

    void updateFrame(double time);

    bool isAlive();
};

