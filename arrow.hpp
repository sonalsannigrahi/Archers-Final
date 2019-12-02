#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>


class Arrow{
    private:
        float xpos;
        float ypos;
        float angle;//will be used to render the graphics
        
        //need to include the files for sprites
        sf::Texture texture;
        if (!texture.loadFromFile("image.png"))
        {
            // error...
        }
    public:
        Arrow();
        Arrow(float x, float y, float angle);

        

        //ask physics team for specifications
        void move();
};
