//
//  Balloon.cpp
//  ArchersGame
//
//  Created by Sunho Hwang on 27/11/2019.
//  Copyright © 2019 Sunho Hwang. All rights reserved.
//

#include "Balloon.hpp"


void Balloon::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

Balloon::Balloon() {
    sf::Texture texture;
    texture.loadFromFile(balloonconstants.filename);
    sprite = sf::Sprite(texture);
    sprite.setPosition(0.f,0.f);
}

void Balloon::setSize(int width, int height) {
    windowWidth = width;
    windowHeight = height;
}

void Balloon::updateFrame(double time) {
    window -> draw(sprite);
    float y = balloonconstants.ypos;
    sprite.move(0.f,y * time);
}

