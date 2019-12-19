#include "opponent.hpp"

Opponent::Opponent(double x = 600, double y = 400, Arrow arrow, float health = 1):Character(x, y, arrow, health) {
    sf::Texture texture;
    texture.loadFromFile("Assets/opponentsprite.png");
    this->opponent.setTexture(texture);
}

void Opponent::setWindow(sf::RenderWindow* gameWindow){
    //set window to game window
	window = gameWindow;
}

void Opponent::setSize(int width, int height ){
    winWidth = width;
	winHeight = height;
}

void Opponent::setPosition(double x, double y) {
    opponent.setPosition(x.f, y.f);
}

void Opponent::getPosition() {
    return opponent.getPosition()
}

bool Opponent::isAlive(){
    return alive;
}

void Opponent::updateFrame(double time) {
    opponent.setPosition(x.f, y.f);
    opponent.setScale(0.3f, 0.3f);
    window.draw(opponent);
}

