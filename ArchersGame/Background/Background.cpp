//
//  Background.cpp
//  ArchersGame
//
//  Created by Sunho Hwang on 22/11/2019.
//  Copyright © 2019 Sunho Hwang. All rights reserved.
//

#include "Background.hpp"

Background::Background(){
    backgroundTexture.loadFromFile("Background/Asset/" + backgroundConstants.filename);
    backgroundSprite = sf::Sprite(backgroundTexture);
}

void Background::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Background::updateFrame(double time) {
    //std::cout << "Yo i was here" << std::endl;
    window -> draw(backgroundSprite);
}
