#include "opponent.hpp"

Opponent::Opponent(double x = 600, double y = 400, Arrow arrow, float health = 1, float scale = 0.35):Character(x, y, arrow, health) {
    /*
    sf::Texture texture_arm_bow;
    texture_arm_bow.loadFromFile(""); // add file
    this->arm_bow.setTexture(texture_arm_bow);
    sf::Texture texture_opponent;
    texture_opponent.loadFromFile(""); // add file
    this->opponent.setTexture(texture_opponent);
    // define random numbers to set opponent's position
    opponent.setPosition(0.f, 0.f); // set opponent's position (randomly)
    arm_bow.setPosition(0.f, 0.f); // set position of the bow compared to opponent
    */

    sf::Texture texture;
    texture.loadFromFile("Assets/opponentsprite.png");
    this->opponent.setTexture(texture);
    opponent.setPosition(x.f, y.f);
    opponent.setScale(scale, scale);
}

void Opponent::setPosition(double x, double y) {
    opponent.setPosition(x.f, y.f);
}

void Opponent::getPosition() {
    return opponent.getPosition()
}

void Opponent::updateFrame(double time) {
    
}