#ifndef PLAYER_BOX_HPP_INCLUDED
#define PLAYER_BOX_HPP_INCLUDED

#include "fire_balls.hpp"

#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>

class PLayerBox: public sf::Drawable{
public:
    sf::RenderWindow* window;

    double W;
    double H;

    double pos_x;
    double pos_y;

    double length;

    double angriness;
    double MAX_SPEED;
    double MAX_TIME_TO_ANGRY;
    double MAX_TIME_TO_CALM;

    bool under_pressure;

    void move_to_right();
    void move_to_left();

    /**
    double IntTime;
    double IntTime_margin;
    **/


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        sf::RectangleShape shape(sf::Vector2f(length, length));
        int color = (int)((angriness/100.0) * 255);

        shape.setFillColor(sf::Color(color,100,0));
        shape.setPosition(pos_x - length/2, window->getSize().y - (pos_y + length/2) );

        target.draw(shape);
    }

public:
    PLayerBox(sf::RenderWindow* window, double pos_x, double pos_y, double length,double W,double H);
    void resolve_event(sf::Event event, double mouse_x, double mouse_y);

    bool will_throw();

    FIRE_BALL* hurl(double mouse_x, double mouse_y);

    void update(double duration);

    ///void DRAW_PATH(double mouse_x, double mous_y);

    FIRE_BALL* run(double duration, double mouse_x, double mouse_y);

};

#endif // PLAYER_BOX_HPP_INCLUDED



