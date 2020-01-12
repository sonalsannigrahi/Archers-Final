#ifndef PLAYER_BOX_HPP_INCLUDED
#define PLAYER_BOX_HPP_INCLUDED

#include "fire_balls.hpp"
#include "HEALTH_BAR.hpp"

#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>

class PLayerBox: public sf::Drawable{
public:
    sf::RenderWindow* window;

    HealthBar healthBar;

    double W;
    double H;

    int score;

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


    double IntTime;
    double IntTime_margin;



    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        sf::RectangleShape shape(sf::Vector2f(length, length));
        int color = (int)((angriness/100.0) * 255);

        shape.setFillColor(sf::Color(color,100,0));
        shape.setPosition(pos_x - length/2, window->getSize().y - (pos_y + length/2) );
        ///WRITING ANGRINESS
        /**
        sf::Font font;
        font.loadFromFile("ARCADE_ARCHER/font.TTF");
        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string( (int)round(angriness) ));
        text.setFillColor(sf::Color::Red);


        int char_size = 5;
        text.setCharacterSize(char_size);

        double W_MIN = text.getLocalBounds().width;
        double H_MIN = text.getLocalBounds().height;

        text.scale(length/W_MIN, length/H_MIN);
        text.setPosition(pos_x - length/2, target.getSize().y - ( pos_y + length/2 ) );
        **/
        target.draw(shape);
        ///target.draw(text);
    }

public:
    PLayerBox(sf::RenderWindow* window, double pos_x, double pos_y, double length,double W,double H);
    void resolve_event(sf::Event event, double mouse_x, double mouse_y);

    bool will_throw();

    FIRE_BALL* hurl(double mouse_x, double mouse_y);

    std::vector<FIRE_BALL*> resolve_collision(FIRE_BALL* ball);

    void resolve_collisions(FIRE_BALLS& fireBalls);
    void show_health();
    int getHealth();

    void score_inc();
    int  get_score();
    void update(double duration);

    void DRAW_ARROW(double mouse_x, double mous_y);

    FIRE_BALL* run(double duration, double mouse_x, double mouse_y);

};

#endif // PLAYER_BOX_HPP_INCLUDED



