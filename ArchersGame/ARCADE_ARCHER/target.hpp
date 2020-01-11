#ifndef TARGET_HPP_INCLUDED
#define TARGET_HPP_INCLUDED

#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>

class Target: public sf::Drawable{
private:

    double Age, MaxAge;
    bool isAlive;

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
    Target(double pos_x, double pos_y, double length, sf::RenderWindow* window);
    void update(double duration);
    bool alive();
};

#endif // TARGET_HPP_INCLUDED