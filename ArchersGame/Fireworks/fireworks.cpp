
#include "fireworks.hpp"
Fireworks::Fireworks(){
  
    for (int i = 0; i < fireworksconstants.filename_len; i++){
        sf::Texture* texture = new sf::Texture();
        texture -> loadFromFile("Fireworks/asset/"+fireworksconstants.filename[i]);
        sf::Sprite* sprite = new sf::Sprite(*texture);
        fireSprites.push_back(*sprite);
    }   
 
}

void Fireworks::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}
void Fireworks::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;
    //sets a random position within the window 
    posX = rand() % windowWidth;
    posY = (rand() % windowHeight) * fireworksconstants.skylimit;
    for (int i = 0; i < fireworksconstants.filename_len; i++){
        fireSprites[i].setPosition(posX, posY);
        fireSprites[i].setScale(fireworksconstants.scalex, fireworksconstants.scaley);
    }
}


void Fireworks::updateFrame(double time) {
    counter += time;
    if (counter >= fireworksconstants.changetimefireworks){
        counter -= fireworksconstants.changetimefireworks;
        current ++;
        if (current == fireworksconstants.filename_len){
            alive = false;
            current = 0;
        }
    }
    if (alive){
        window -> draw(fireSprites[current]);
    }
}

bool Fireworks::isAlive(){
    return alive;
}