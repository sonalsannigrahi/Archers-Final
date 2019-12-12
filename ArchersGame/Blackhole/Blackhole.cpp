#include "Blackhole.hpp"

Blackhole::Blackhole(){
    srand(time(NULL));
    for (int i = 0; i < blackholeConstants.filename_length; i++){
        sf::Texture* texture = new sf::Texture();
        texture -> loadFromFile("Blackhole/Assets/blackhole" + blackholeConstants.filename[i]);
        sf::Sprite* sprite = new sf::Sprite(*texture);
        blackholeSprites.push_back(*sprite);
    }
}

void Blackhole::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Blackhole::setSize(int width, int height){
    blackholeWidth = width;
    blackholeHeight = height;
}

void Blackhole::setBlackholePosition(float x, float y){
  for (int i =0; i < blackholeConstants.filename_length; i++){
    blackholeSprites[i].setPosition(x,y);
  }
}

void Blackhole::updateFrame(double time) {
  counter = counter + time;
  if (counter >= blackholeConstants.changetime){
    counter -= blackholeConstants.changetime;
    current += 1;
    if (current >= blackholeConstants.filename_length) current = 0;
  }
  window -> draw(blackholeSprites[current]);
}
