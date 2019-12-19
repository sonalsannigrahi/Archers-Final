#include "character.hpp"

// To do: add default size
Character::Character(double x, double y, Arrow arrow, float health = 1) {
    this->health = health;
    this->xPosition = x;
    this->yPosition = y;
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

Arrow Character::getArrow() {
    return arrow;
}

void Character::setWindow(sf::RenderWindow* gameWindow) {
    window = gameWindow;
}

// setGround --> to implement later on

// updateFrame ?