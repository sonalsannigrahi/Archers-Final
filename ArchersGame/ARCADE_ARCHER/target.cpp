#include "target.hpp"

Target::Target(double pos_x, double pos_y, double length, sf::RenderWindow* window)
{
    this->Age = 0.0;
    this->MaxAge = 4.0;

    bool isAlive = true;

    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->length = length;

    this->window = window;
}

void Target::update(double duration)
{
    this->Age += duration;
}

bool Target::alive()
{
    if(Age >= MaxAge){
        return false;
    }
    return true;
}
