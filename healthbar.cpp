#include "healthbar.hpp"

Healthbar::Healthbar(float health = 1) {
    this->health = health;
    sf::Texture texture_rect;
    texture_rect.loadFromFile("Assets/healthbar_moving.png");
    this->rectangle.setTexture(texture_rect);
    rectangle.setPosition(0.f, 0.f);
    sf::Texture texture_green;
    texture_green.loadFromFile("Assets/healthbar_rectangle.png");
    sf::Texture texture_orange;
    texture_orange.loadFromFile("Assets/healthbar_rectangle.png");
    sf::Texture texture_red;
    texture_red.loadFromFile("Assets/healthbar_rectangle.png");
    if (0.25 < health < 1) {
        this->filling.setTexture(texture_green);
    } else if (0.10 < health <= 0.25) {
        this->filling.setTexture(texture_orange);
    } else {
        this->filling.setTexture(texture_red);
    }
    this->filling.setScale(health, 1.0f); // default values, real values tbd
    filling.setPosition(114.f, 31.f);
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
    sf::Texture texture_green;
    texture_green.loadFromFile("Assets/healthbar_rectangle_g.png");
    sf::Texture texture_orange;
    texture_orange.loadFromFile("Assets/healthbar_rectangle_o.png");
    sf::Texture texture_red;
    texture_red.loadFromFile("Assets/healthbar_rectangle_r.png");
    if (0.25 < health < 1) {
        filling.setTexture(texture_green);
    } else if (0.10 < health <= 0.25) {
        filling.setTexture(texture_orange);
    } else {
        filling.setTexture(texture_red);
    }
    this->filling.setScale(health, 1.0f);

    window -> draw(rectangle);
    window -> draw(filling);
}