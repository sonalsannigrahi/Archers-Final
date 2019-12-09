#include "healthbar.hpp"

Healthbar::Healthbar(float health = 1) {
    this->health = health;
    sf::Texture texture1;
    texture1.loadFromFile("healthbar_moving.png");
    this->rectangle.setTexture(texture1);
    sf::Texture texture2;
    texture2.loadFromFile("healthbar_rectangle.png");
    this->filling.setTexture(texture2);
    this->filling.setScale(health, 1.0f); // default values, real values tbd
}

void Healthbar::setWindow(sf::RenderWindow* gameWindow){
	window = gameWindow;
}

void Healthbar::setSize(int width, int height) {
    this->healthWidth = width;
    this->healthHeight = height;
    // sprite resize
}

void Healthbar::updateFrame(double time) {
    // get player's health
    float health = player.getHealth(); // how do I get the player's health?
    // update size of the health (change filling size)
    this->filling.setScale(health, 1.0f);
    
    window -> draw(rectangle);
    window -> draw(filling);
}