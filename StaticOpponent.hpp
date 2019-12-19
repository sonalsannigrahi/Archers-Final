#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class StaticOpponent: {

private:

    sf::RenderWindow* window;

    std::vector<sf::Sprite> opponentSprites;
    // sf::Sprite arm_bow;
    sf::Sprite opponent;
    int winWidth, winHeight;

    bool alive = true;

    double timer;

public:

    StaticOpponent();

    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);

    void setPosition(double x, double y);
    void getPosition();

    void updateFrame(double time);

    bool isAlive();
    bool isShot(float X, float Y);

    void updateHealth();
}

