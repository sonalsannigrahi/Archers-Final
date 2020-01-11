#include "HEALTH_BAR.hpp"

HealthBar::HealthBar(sf::RenderWindow* window)
{
    this->window = window;

    this->health = 0;
}

void HealthBar::set_health(int health)
{
    this->health = health;
}

void inc_health(int inc)
{
    this->health += inc;
}


void show()
{
    double W = window->getSize().x;
    double H = window->getSize().y;

    int N = 10;

    sf::RectangleShape rectangle(sf::Vector2f(W, H/N));
    rectangle.setFillColor(sf::Color(255, 0, 0, 0));

    window->draw(rectangle);

}
