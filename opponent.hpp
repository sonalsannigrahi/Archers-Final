#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "character.hpp"

class Opponent: public Character {

private:

    sf::RenderWindow* window;

    std::vector<sf::Sprite> opponentSprites;
    // sf::Sprite arm_bow;
    sf::Sprite opponent;
    int winWidth, winHeight;

    bool alive = true;

    double timer;

public:

    Opponent(double x, double y, Arrow arrow, float health = 1, float scale = 0.35);

    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);

    void setPosition(double x, double y);
    void getPosition();

    void updateFrame(double time);

    bool isAlive();
    bool isShot(float X, float Y);
}

