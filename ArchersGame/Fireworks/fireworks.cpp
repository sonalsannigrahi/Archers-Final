
#include "fireworks.hpp"

void Firework::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Firework::updateFrame(double time) {
    counter += time;
    if (counter >= fireworksconstants.changetimefireworks){
        counter = 0;
        current ++;
        if (current == fireworksconstants.filename_len){
            current = 0;
        }
    }
     sf::Texture texture;
    texture.loadFromFile("Fireworks/asset/"+fireworksconstants.filename[current]);
    //std::cout << "Yo i was here" << std::endl;
    sf::Sprite sprite(texture);
    window -> draw(sprite);