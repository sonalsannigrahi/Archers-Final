#ifndef BOX_PARTICLE_HPP_INCLUDED
#define BOX_PARTICLE_HPP_INCLUDED

#include "VECTOR_2D.hpp"

#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

class BoxParticle: public sf::Drawable{
private:
    sf::RenderWindow* window;

    double length;
    double mass;

    Vector2D Pos;
    Vector2D Vel;

    double angle;
    double angle_vel;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {

        sf::ConvexShape shape;
        shape.setPointCount(4);

        ///MAY HAVE PROBLEMS WITH NORMALIZE
        Vector2D e_1(1.0,0);
        e_1.turn(angle);

        Vector2D e_2 = e_1;
        e_2.turn(pi/2);


        Vector2D p_1 = (length/2) * (e_1 + e_2);
        p_1 = p_1 + Pos;

        Vector2D p_2 = (length/2) * (e_2 - e_1);
        p_2 = p_2 + Pos;

        Vector2D p_3 = (-length/2) * (e_1 + e_2);
        p_3 = p_3 + Pos;

        Vector2D p_4 = (length/2) * (e_1 - e_2);
        p_4 = p_4 + Pos;

        shape.setPoint(0,sf::Vector2f(p_1.get_x(),target.getSize().y-p_1.get_y()));
        shape.setPoint(1,sf::Vector2f(p_2.get_x(),target.getSize().y-p_2.get_y()));
        shape.setPoint(2,sf::Vector2f(p_3.get_x(),target.getSize().y-p_3.get_y()));
        shape.setPoint(3,sf::Vector2f(p_4.get_x(),target.getSize().y-p_4.get_y()));

        target.draw(shape);
    }

public:

    BoxParticle(sf::RenderWindow* window, double length, double mass, Vector2D Pos, Vector2D Vel, double angle, double angle_vel);

    void update(double duration);
    bool check_if_outside_of_border();
};

#endif // BOX_PARTICLE_HPP_INCLUDED


