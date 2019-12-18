
#include "Opponent.hpp"

Opponent::Opponent(){

    for (int i = 0; i < charconstant.filenamelen; i++){
        sf::Texture* texture = new sf::Texture();
        texture -> loadFromFile("Opponent/Assets/"+ charconstant.filename[i]);
        sf::Sprite* sprite = new sf::Sprite(*texture);
        oppSprites.push_back(*sprite);
    }   
}

void Opponent::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Opponent::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;
    posX = 0;
    posY = 0;
}

void Opponent::updateFrame(double time) {
    sf::Vector2u windowSize;

    windowSize = window -> getSize();

    posX = float(windowSize.x)/25;
    posY = float(windowSize.y)/5;      
    counter = counter + time;
    if (counter >= charconstant.changetime ) {
        counter -= charconstant.changetime;
        current += 1;
    }
    
    if (direction == 0){
        posX += charconstant.charSpeed * time;
    } else {
        posX -= charconstant.charSpeed * time;
    }
    if (posX < 0.0 || posX > (float) windowWidth){
        alive = false; 
    } else {
        oppSprites[current].setPosition(posX, posY);
        window -> draw(oppSprites[current]);
    }
}

bool Opponent::isAlive(){
    return alive;
}

