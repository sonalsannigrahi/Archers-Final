#ifndef TRACE_HPP_INCLUDED
#define TRACE_HPP_INCLUDED

#include "VECTOR_2D.hpp"
#include "trace_constants.hpp"

#include<bits/stdc++.h>
#include <SFML/Graphics.hpp>

class Trace: public sf::Drawable{
private:
///public:
    double Age;
    double radius;

    Vector2D pos;

    bool isAlive;

    TraceConstants constants;

    ///TO BE CHANGED
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        ///std::cout << "AHHHHHH" << std::endl;
        ///ORIGINAL ONE
        /**
        sf::CircleShape shape(radius);

        shape.setFillColor(sf::Color(255, 213, 0));


        shape.setPosition(pos.get_x()-radius,target.getSize().y - (pos.get_y() + radius) );
        target.draw(shape);
        **/
        ///TO GIVE ARCADE STYLE
        double W = target.getSize().x;
        double H = target.getSize().y;

        int L = 4;
        for(int i = (int)floor((pos.get_x()-radius)/L); i <= (int)ceil((pos.get_x()+radius)/L); i++){
            for(int j = (int)floor((pos.get_y()-radius)/L); j <= (int)ceil((pos.get_y()+radius)/L); j++){
                double center_x = (i - 0.5) * L;
                double center_y = (j - 0.5) * L;
                double dist = sqrt(pow(center_x - pos.get_x(),2.0)+pow(center_y - pos.get_y(),2.0));
                if(dist <= radius){
                    sf::RectangleShape shape(sf::Vector2f(L,L));
                    shape.setFillColor(sf::Color(255, 213, 0));
                    shape.setPosition(center_x - L/2, H - (center_y + L/2));
                    target.draw(shape);
                }
            }
        }
    }

public:
    Trace(TraceConstants& constants, Vector2D pos);
    void update(double duration);
    bool alive();
};

#endif // TRACE_HPP_INCLUDED
