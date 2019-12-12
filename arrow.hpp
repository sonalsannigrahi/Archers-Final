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
        sf::Sprite arrow;
        //File included will depend on arrow types(not yet implemented but will be used for future levels)
        
    public:
        Arrow();
        Arrow(float x, float y, float angle, std::string filename);

        //ask physics team for specifications
        void shoot();
};
