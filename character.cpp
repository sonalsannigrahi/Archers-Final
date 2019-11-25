#include "character.hpp"

Character::Character(float health = 1, double x, double y) {
    this->health = health;
    this->xPosition = x;
    this->yPosition = y;
}

double Character::getX() const {
    return xPosition;
}

double Character::getY() const {
    return yPosition;
}
