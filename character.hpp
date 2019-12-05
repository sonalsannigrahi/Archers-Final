#include <SFML/Graphics.hpp>

#include "bow.hpp"
#include "arrow.hpp"
#include "healthbar.hpp"

class Character: public sf::Drawable 
{
private:

    /* health attribute, values between 0 and 1, can be turned into a percentage
    1: healthy, 0: dead */

    double xPosition, yPosition;

    Healthbar healthbar; 

    Bow bow;

    Arrow arrow;

public:

    // constructor (health initialized to 1 by default)
    Character(double x, double y, Bow bow, Arrow arrow, float health = 1);

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
