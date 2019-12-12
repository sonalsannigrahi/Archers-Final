#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "arrow.hpp"
#include "healthbar.hpp"
#include "ArchersGame/Ground/Ground.hpp"

class Character:
{
private:

    double xPosition, yPosition;
    float health; 
    Arrow arrow;
    sf::RenderWindow* window;
    int characterWidth, characterHeight;
    double timer; // don't know if that one should be in character or player/opponent
    Ground* ground_p;

public:

    // constructor (health initialized to 1 by default)
    Character(double x, double y, Arrow arrow, float health = 1);

    // get position functions
    double getX();
    double getY();

    // get health function
    float getHealth();

    // get arrow
    Arrow getArrow();

    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void setGround(Ground* ground_p); // useful here?

    // changeHealth function, will depend on collisions --> physics


    /* updateFrame function
    inside the character class or player/opponent
    */

};
