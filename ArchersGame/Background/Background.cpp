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

void Background::setSize(int width, int height){
    backgroundWidth = width;
    backgroundHeight = height;
    backgroundSprite.setScale((float) width / backgroundSprite.getGlobalBounds().width, (float) height / backgroundSprite.getGlobalBounds().height);
}

void Background::updateFrame(double time) {
    sf::Texture texture;
    texture.loadFromFile("Background/Asset/PNG/game_background_3/bg3.png");
    //std::cout << "Yo i was here bgimg" << std::endl;
    sf::Sprite sprite(texture);
    window -> draw(sprite);
    //std::cout << "Yo i was here" << std::endl;
    window -> draw(backgroundSprite);
}
