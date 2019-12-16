#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "character.hpp"

class Opponent: public Character {

private:

    std::vector<sf::Sprite> opponentSprites;
    // sf::Sprite arm_bow;
    sf::Sprite opponent;
    

public:

    Opponent(double x, double y, Arrow arrow, float health = 1, float scale = 0.35);

    void setPosition(double x, double y);
    void getPosition();

    void updateFrame(double time);


}

