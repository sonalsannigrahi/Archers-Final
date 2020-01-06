#include "Spear.hpp"
#include "../Character/bow.hpp"

Spear::Spear(Player* player){
    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile("Opponent/Assets/defeat.png");
    defeat -> setTexture(*texture);
    sf::Texture* background = new sf::Texture();
    background -> loadFromFile("Opponent/Assets/defback.png");
    defback -> setTexture(*background);
    for (int i = 0; i < spearconstant.filenamelen; i++){
        sf::Texture* texture = new sf::Texture();
        texture -> loadFromFile("Opponent/Assets/"+ spearconstant.filename[i]);
        sf::Sprite* sprite = new sf::Sprite(*texture);
        sprite -> setScale(0.65f,0.65f);
        spearSprites.push_back(*sprite);
    }
}

void Spear::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Spear::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;

    float angle = -60 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(120)));
    posX = rand()%(width/2) + float(width)/8;
    posY = -rand()%(height/3) + float(height)/2;
    for (int i =0; i < spearconstant.filenamelen; i++){
      spearSprites[i].setPosition(posX,posY);
    }
    defeat -> setScale(0.8f, 0.8f);
    defeat -> setPosition(windowWidth/4.7, windowHeight/8);
    defback -> setScale(windowWidth, windowHeight);
}

void Spear::updateFrame(double time) {
  counter = counter + time;
  if (counter >= spearconstant.changetime){
    counter -= spearconstant.changetime;
    current += 1;
    if (current >= spearconstant.filenamelen) current = 0;
  }
  window -> draw(spearSprites[current]);
}

bool Spear::isAlive(){
    return alive;
}
