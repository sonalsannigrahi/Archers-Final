//
//  Background.cpp
//  ArchersGame
//
//  Created by Sunho Hwang on 22/11/2019.
//  Copyright © 2019 Sunho Hwang. All rights reserved.
//

#include "Background.hpp"

void Background::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Background::updateFrame(double time) {
    sf::Texture texture;
    texture.loadFromFile("Background/Asset/PNG/game_background_3/bg3.png");
    //std::cout << "Yo i was here bgimg" << std::endl;
    sf::Sprite sprite(texture);
    window -> draw(sprite);
}
