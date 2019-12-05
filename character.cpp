#include "character.hpp"

Character::Character(double x, double y, Bow bow, Arrow arrow, float health = 1) {
    this->healthbar = Healthbar(float health);
    this->xPosition = x;
    this->yPosition = y;
    this->bow = bow;
    this->arrow = arrow;
}

double Character::getX() {
    return xPosition;
}

double Character::getY() {
    return yPosition;
}

float Character::getHealth() {
    return healthbar.health;
}

Bow Character::getBow() {
    return bow;
}

Arrow Character::getArrow() {
    return arrow;
}