#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "character.hpp"

class Opponent: public Character {

private:
    std::vector<sf::Sprite> opponentSprites;
    sf::Sprite arm_bow;
    sf::Sprite opponent;
    

public:

    Opponent(double x, double y, Arrow arrow, float health = 1, int width, int height);

    // set position functions
    void setX(double x);
    void setY(double y);
    void setPosition(double x, double y);

    /* update function
    what type? and what should it do?
    type update()
    */

}

