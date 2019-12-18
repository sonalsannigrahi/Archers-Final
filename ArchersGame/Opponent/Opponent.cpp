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
    
    posX = float(width)/25;
    posY = float(height)/5;      
}

void Opponent::updateFrame(double time) {
    counter = counter + time;
    if (counter >= charconstant.changetime ) {
        counter -= charconstant.changetime;
        current += 1;
        current %= charconstant.filenamelen;
    }
    
    if (direction == 0){
        posX += charconstant.charSpeed * time;
    } else {
        posX -= charconstant.charSpeed * time;
    }

    //std::cout << posX << " " << posY << std::endl;

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

