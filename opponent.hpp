#include <SFML/Graphics.hpp>

class Opponent: public sf::Drawable 
{
private:

    /* health attribute, values between 0 and 1, can be turned into a percentage
    1: healthy, 0: dead */
    float health; 

    double xPosition, yPosition;

private:

    // constructor
    Opponent(float health = 1, double x, double y);

    // get position functions
    double getX() const;
    double getY() const;


    // set position functions
    void setX(double x);
    void setY(double y);
    void setPosition(double x, double y);

    /* update function
    what type? and what should it do?
    type update()
    */

    // draw opponent function

}
