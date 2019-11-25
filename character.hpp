#include <SFML/Graphics.hpp>

class Character: public sf::Drawable 
{
private:

    /* health attribute, values between 0 and 1, can be turned into a percentage
    1: healthy, 0: dead */
    float health; 

    double xPosition, yPosition;

public:

    // constructor
    Character(double x, double y);

    // get position functions
    double getX() const;
    double getY() const;

    // get health function
    float getHealth();

    //smfl objects for graphics
    sf::CircleShape head;
    sf::RectangleShape body;
    sf::RectangleShape left_arm;
    sf::RectangleShape right_arm;
    sf::RectangleShape left_leg;
    sf::RectangleShape right_leg;

    /* only add these functions if we need to change the position of the character
    more useful for the opponent class
    // set position functions
    void setX(double x);
    void setY(double y);
    */

    /* update function
    what type? and what should it do?
    type update()
    */

    // draw character function
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
