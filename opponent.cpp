#include "opponent.hpp"

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

