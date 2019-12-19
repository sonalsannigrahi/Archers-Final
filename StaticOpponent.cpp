#include "StaticOpponent.hpp"

StaticOpponent::StaticOpponent(float health = 1) {
    sf::Texture texture;
    texture.loadFromFile("Assets/opponentsprite.png");
    this->opponent.setTexture(texture);
}

/*
void StaticOpponent:updateHealth() {
    // to implement
}
*/

void StaticOpponent::setWindow(sf::RenderWindow* gameWindow){
    //set window to game window
	window = gameWindow;
}

void StaticOpponent::setSize(int width, int height ){
    winWidth = width;
	winHeight = height;
}

void StaticOpponent::setPosition(double x, double y) {
    opponent.setPosition(x.f, y.f);
}

void StaticOpponent::getPosition() {
    return opponent.getPosition();
}

bool StaticOpponent::isAlive(){
    return alive;
}

void StaticOpponent::updateFrame(double time) {
    opponent.setPosition(x.f, y.f);
    opponent.setScale(0.3f, 0.3f);
    window -> draw(opponent);
}

