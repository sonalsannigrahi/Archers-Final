#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>
#include "physics.cpp"


class Arrow: public Rectangle{
    private:
        //need to include the files for sprites
        sf::Texture texture;
        //File included will depend on arrow types(not yet implemented but will be used for future levels)
        
    public:
        Arrow();
        Arrow(float x, float y, float angle, std::string filename);

        //ask physics team for specifications
        void shoot();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
