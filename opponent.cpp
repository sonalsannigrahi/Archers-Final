#include "opponent.hpp"

Opponent::Opponent(double x, double y, Arrow arrow, float health = 1, int width, int height):Character(x, y, arrow, health, width, height) {
    sf::Texture texture_arm_bow;
    texture_arm_bow.loadFromFile(""); // add file
    this->arm_bow.setTexture(texture_arm_bow);
    sf::Texture texture_opponent;
    texture_opponent.loadFromFile(""); // add file
    this->opponent.setTexture(texture_opponent);
    // define random numbers to set opponent's position
    opponent.setPosition(0.f, 0.f); // set opponent's position (randomly)
    arm_bow.setPosition(0.f, 0.f); // set position of the bow compared to opponent
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

