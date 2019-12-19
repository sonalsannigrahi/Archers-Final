#include "Arrow.hpp"

Arrow::Arrow(){
    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile("Arrow/Assets/arrow.png" + arrowConstants.filename);
    arrowSprite = new sf::Sprite(*texture); 
}

void Arrow::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;
}

void Arrow::setWindow(sf::RenderWindow* gameWindow){
    this -> window = gameWindow;
}

bool Arrow::isAlive(){
    return alive;
}




