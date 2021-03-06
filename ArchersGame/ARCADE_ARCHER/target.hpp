#ifndef TARGET_HPP_INCLUDED
#define TARGET_HPP_INCLUDED

#include "fire_balls.hpp"
#include "BOX_PARTICLES.hpp"
#include "VECTOR_2D.hpp"
#include "player_box.hpp"

#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>

double SIMULATE(Vector2D Pos, Vector2D Vel);

class Target: public sf::Drawable{
///private:
public:

    int Level;

    double Age, MaxAge;
    bool isAlive;

    double counter_for_hurling;
    double interval_for_hurling;

    double pos_x,pos_y;
    double length;

    sf::RenderWindow* window;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        sf::RectangleShape shape(sf::Vector2f(length,length));
        shape.setPosition(pos_x - length/2, window->getSize().y - (pos_y + length/2));

        target.draw(shape);
    }

public:
    Target(int Level, double pos_x, double pos_y, double length, sf::RenderWindow* window);
    void update(double duration);

    std::pair< std::vector<FIRE_BALL*>, std::vector<BoxParticle*> > resolve(FIRE_BALL* ball);

    FIRE_BALL* hurl(PLayerBox& playerBox);

    bool alive();
};

#endif // TARGET_HPP_INCLUDED
