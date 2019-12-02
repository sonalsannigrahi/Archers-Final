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
    srand(time(NULL));
    sf::Texture texture;
    texture.loadFromFile(balloonconstants.filename);
    sprite = sf::Sprite(texture);
    sprite.setPosition( rand()%windowWidth , 0.f);
}

void Balloon::setSize(int width, int height) {
    windowWidth = width;
    windowHeight = height;
}

void Balloon::updateFrame(double time) {
    window -> draw(sprite);
    float y = balloonconstants.ypos;
    if (sprite.getGlobalBounds().top < 0.0 || sprite.getGlobalBounds().top > (float) windowHeight){
            active = false; // Balloon out of frame => delete it
        } else {
            sprite.move(0.f,y*time);
        }
    }

bool Balloon::isActive(){
        return active;
    }

