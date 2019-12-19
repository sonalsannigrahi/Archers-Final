#include "Opponent.hpp"

Opponent::Opponent(){

    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile("Opponent/Assets/defeat.png");
    defeat -> setTexture(*texture);
    sf::Texture* background = new sf::Texture();
    background -> loadFromFile("Opponent/Assets/defback.png");
    defback -> setTexture(*background);
    for (int i = 0; i < charconstant.filenamelen; i++){
        sf::Texture* texture = new sf::Texture();
        texture -> loadFromFile("Opponent/Assets/"+ charconstant.filename[i]);
        sf::Sprite* sprite = new sf::Sprite(*texture);
        sprite -> setScale(0.4f,0.4f);
        oppSprites.push_back(*sprite);
    }
}

void Opponent::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Opponent::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;

    posX = width - float(width)/25; // set to opposite end of window
    posY = float(height)/2;
    comparison = float(width)/25;
    defeat -> setScale(0.8f, 0.8f);
    defeat -> setPosition(windowWidth/4.7, windowHeight/8);
    defback -> setScale(windowWidth, windowHeight);
}

void Opponent::updateFrame(double time) {
    counter = counter + time;
    if (counter >= charconstant.changetime ) {
        counter -= charconstant.changetime;
        current += 1;
        current %= charconstant.filenamelen;
    }

    if (direction == 0){
        posX -= charconstant.charSpeed * time; // run in left direction
    } else {
        posX += charconstant.charSpeed * time;
    }

    //std::cout << posX << " " << posY << std::endl;

    if (posX < comparison + 30 || posX > (float) windowWidth){
        alive = false; // sprite has reached out of window
        window -> draw(*defback); //semi transparent black screen, maybe call game pause
        window -> draw(*defeat); // can be removed, defeat screen
    } else {
        oppSprites[current].setPosition(posX, posY);
        window -> draw(oppSprites[current]);

    }
}

bool Opponent::isAlive(){
    return alive;
}
