#include <SFML/Graphics.hpp>

#include "bow.hpp"
#include "arrow.hpp"

class Character: public sf::Drawable 
{
private:

    /* health attribute, values between 0 and 1, can be turned into a percentage
    1: healthy, 0: dead */
    float health; 

    double xPosition, yPosition;

    Bow bow;

    Arrow arrow;

public:

    // constructor
    Character(double x, double y, Bow bow, Arrow arrow);

    // get position functions
    double getX();
    double getY();

    // get health function
    float getHealth();

    // get bow
    Bow getBow();

    // get arrow
    Arrow getArrow();

    //smfl objects for graphics
    sf::CircleShape head;
    sf::RectangleShape body;
    sf::RectangleShape left_arm;
    sf::RectangleShape right_arm;
    sf::RectangleShape left_leg;
    sf::RectangleShape right_leg;

    /* update function
    what type? and what should it do?
    type update()
    */

    // draw character function
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
