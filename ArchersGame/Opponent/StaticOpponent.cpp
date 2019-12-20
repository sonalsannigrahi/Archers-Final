#include "StaticOpponent.hpp"

StaticOpponent::StaticOpponent() {
    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile("Opponent/Assets/opponentsprite.png");
    opponent -> setTexture(*texture);
}

void StaticOpponent::setWindow(sf::RenderWindow* gameWindow){
    //set window to game window
	window = gameWindow;
}

void StaticOpponent::setSize(int width, int height ){
    winWidth = width;
	winHeight = height;
}

bool StaticOpponent::isAlive(){
    return alive;
}

void StaticOpponent::updateFrame(double time) {
    opponent -> setScale(0.3f, 0.3f);
    window -> draw(*opponent);
}

