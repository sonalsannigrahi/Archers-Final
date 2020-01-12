#ifndef HEALTH_BAR_HPP_INCLUDED
#define HEALTH_BAR_HPP_INCLUDED

#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

class HealthBar{
private:
    int health;

    sf::RenderWindow* window;

public:
    HealthBar(sf::RenderWindow* window);
    void set_health(int health);
    void inc_health(int inc);

    int getHealth();

    void show();
};

#endif // HEALTH_BAR_HPP_INCLUDED
