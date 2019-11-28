#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>


class Arrow: public sf::Drawable{
    private:
        float xpos;
        float ypos;
        float angle;//will be used to render the graphics
        
        //for graphics
        sf::RectangleShape body(sf::Vector2f());
        sf::CircleShape head;//will be set to 3 sides for a triangle
    public:
        Arrow();
        Arrow(float x, float y, float angle);

        virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const;

        //ask physics team for specifications
        void move();
};
