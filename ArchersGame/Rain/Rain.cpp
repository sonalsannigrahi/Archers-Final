#include "Rain.hpp"

Rain::Rain(){
    for (int i = 0; i < rainConstants.filename_length; i++){
        sf::Texture* texture = new sf::Texture();
        texture -> loadFromFile("Rain/Assets/" + rainConstants.filename[i]);
        sf::Sprite*  sprite = new sf::Sprite(*texture);
        rainSprite.push_back(*sprite);
    }
}

void Rain::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Rain::setSize(int width, int height){
    rainWidth = width;
    rainHeight = height;
    for (int i = 0; i < rainConstants.filename_length; i++)
        rainSprite[i].setScale((float) width / rainSprite[i].getGlobalBounds().width, (float) height / rainSprite[i].getGlobalBounds().height);
}

void Rain::updateFrame(double time) {
    //std::cout << "Yo i was here" << std::endl;
    timer += time;
    if (timer >= rainConstants.changeTime){
        timer -= rainConstants.changeTime;
        current++;
        if (current >= rainConstants.filename_length) current = 0;
    }
    window -> draw(rainSprite[current]);
}