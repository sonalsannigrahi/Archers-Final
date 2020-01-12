#include "HEALTH_BAR.hpp"

HealthBar::HealthBar(sf::RenderWindow* window)
{
    this->window = window;

    this->health = 100;
}

void HealthBar::set_health(int health)
{
    this->health = health;
}

void HealthBar::inc_health(int inc)
{
    this->health += inc;
}


void HealthBar::show()
{
    double W = window->getSize().x;
    double H = window->getSize().y;

    int N = 30;

    sf::RectangleShape rectangle(sf::Vector2f( (double)(W * health)/100.0, H/N));
    rectangle.setFillColor(sf::Color(255, 0, 0, 100));

    window->draw(rectangle);

}

int HealthBar::getHealth()
{
    return health;
}