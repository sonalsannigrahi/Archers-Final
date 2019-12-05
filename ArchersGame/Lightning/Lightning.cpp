#include "Lightning.hpp"

Lightning::Lightning(){
    srand(time(NULL));
    for (int i = 0; i < lightningConstants.filename_length; i++){
        sf::Texture* texture = new sf::Texture();
        texture -> loadFromFile("Lightning/Assets/" + lightningConstants.filename[i]);
        sf::Sprite* sprite = new sf::Sprite(*texture);
        lightningSprites.push_back(*sprite);
    }
}

void Lightning::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Lightning::setSize(int width, int height){
    lightningWidth = width;
    lightningHeight = height;
}

void Lightning::updateFrame(double time) {
    timer = std::max(0.0, timer - time);
    //std::cout << "Yo i was here" << std::endl;
    // Draw lightning at a rate
    if (rand() % lightningConstants.lightning_rate == 0) {
        // Choose a random lightning
        id = rand() % lightningConstants.filename_length;
        // Set random x position
        lightningSprites[id].setPosition(rand() % lightningWidth - lightningSprites[id].getGlobalBounds().width / 2, 0.f);
        timer += lightningConstants.time;
    }
    if (timer > 0) window -> draw(lightningSprites[id]);
}
