
#include "fireworks.hpp"
Fireworks::Fireworks(){

<<<<<<< HEAD
    for (int i = 0; i < fireworksconstants.filename_len; i++){
        sf::Texture* texture = new sf::Texture();
        texture -> loadFromFile("Fireworks/asset/"+fireworksconstants.filename[i]);
        sf::Sprite* sprite = new sf::Sprite(*texture);
        fireSprites.push_back(*sprite);
    }   

    
    
}
=======
>>>>>>> 02ab9cbbd4e07f55c97e2a5549d2022a8204cc87
void Fireworks::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}
void Fireworks::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;
    //sets a random position within the window 
    posX = rand() % windowWidth;
    posY = rand() % windowHeight;
    
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
<<<<<<< HEAD
    if (alive){
        fireSprites[current].setPosition(posX, posY);
        window -> draw(fireSprites[current]);
    }
}

bool Fireworks::isAlive(){
    return alive
=======
     sf::Texture texture;
    texture.loadFromFile("Fireworks/asset/"+fireworksconstants.filename[current]);
    //std::cout << "Yo i was here" << std::endl;
    sf::Sprite sprite(texture);
    window -> draw(sprite);
>>>>>>> 02ab9cbbd4e07f55c97e2a5549d2022a8204cc87
}