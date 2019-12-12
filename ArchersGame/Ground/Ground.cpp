#include "Ground.hpp"


Ground::Ground() {
};


void Ground::setWindow(sf::RenderWindow* gameWindow){
  window = gameWindow;
}

void Ground::setSize(int width, int height){
  groundWidth = width;
  groundHeight = height;
}

int Ground::createGround(int style){
  // for (int i = 0; i < groundconstant.filenamelen; i++{
  sf::Texture* texture = new sf::Texture();
  texture -> loadFromFile("Ground/Assets/" + groundconstant.filename[style]);
  sf::Sprite* sprite = new sf::Sprite(*texture);
  groundSprites.push_back(*sprite);
  // }
  return groundSprites.size() - 1;
}

void Ground::updateFrame(double time){
  // mygroundSprites.setPosition(myx,myy);
  // opponentgroundSprites.setPosition(opponentx,opponenty);
  // window -> draw(mygroundSprites);
  // window -> draw(opponentgroundSprites);
  for (int i = 0; i < groundSprites.size(); i++)
    window -> draw(groundSprites[i]);
}


void Ground::setGroundPosition(int id, float x, float y){
  groundSprites[id].setPosition(x, y);
  // if ( id % 2 == 0){
  //   x = rand()%(groundWidth/6) + groundWidth/12;
  //   y = rand()%(groundHeight/2) + groundHeight/4;
  // }
  // if ( id % 2 == 1){
  //   x = rand()%(groundWidth/4) + groundWidth*5/12;
  //   y = rand()%(groundHeight/2) + groundHeight/4;
  // }
}

sf::Vector2f Ground::getGroundPosition(int id){
  return groundSprites[id].getPosition();
}

void Ground::deleteGround(int id){
    sf::Texture* texture = new sf::Texture();
    groundSprites[id].setTexture(*texture);
}
