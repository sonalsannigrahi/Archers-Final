#include "Arrow.hpp"

Arrow::Arrow(){
    // This function is for testing purpose only

    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile("Arrow/Assets/" + arrowConstants.filename);
    arrowSprite = new sf::Sprite(*texture); 
    arrowSprite -> setScale(arrowConstants.scale, arrowConstants.scale);

    posX = 10;
    posY = 400;
    vX = 400;
    vY = -200;
}

Arrow::Arrow(float posX, float posY, float vX, float vY){
    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile("Arrow/Assets/" + arrowConstants.filename);
    arrowSprite = new sf::Sprite(*texture); 
    arrowSprite -> setScale(arrowConstants.scale, arrowConstants.scale);

    this -> posX = posX;
    this -> posY = posY;
    this -> vX = vX;
    this -> vY = vY;
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

void Arrow::updateFrame(double time){
    vY += arrowConstants.gravity * time;
    posX += vX * time;
    posY += vY * time;
    angle = atan2(vY, vX) * 180 / 3.14159265359;
    if (posX >= 0 && posX <= windowWidth && posY >= 0 && posY <= windowHeight){
        arrowSprite -> setPosition(posX, posY);
        arrowSprite -> setRotation(angle);
        window -> draw(*arrowSprite);
    } else {
        alive = false;
    }
}




