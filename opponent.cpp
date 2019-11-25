#include "opponent.hpp"

Opponent::Opponent(float health = 1, double x, double y) {
    this->health = health;
    this->xPosition = x;
    this->yPosition = y;
}

double Opponent::getX() const {
    return xPosition;
}

double Opponent::getY() const {
    return yPosition;
}

void Opponent::setX(double x) {
    this->xPosition = x;
}

void Opponent::setY(double y) {
    this->yPosition = y;
}

void Opponent::setPosition(double x, double y) {
    setX(double x);
    setY(double y);
}