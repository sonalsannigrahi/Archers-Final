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
    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile(balloonconstants.filename);
    sprite = sf::Sprite(*texture);
}

void Balloon::setSize(int width, int height) {
    windowWidth = width;
    windowHeight = height;
    sprite.setPosition( rand()%windowWidth , 0.f);
    sprite.setScale(balloonconstants.xscale, balloonconstants.yscale);
}

void Balloon::updateFrame(double time) {
    //std::cout << "Balloon at " << sprite.getGlobalBounds().top << " " << sprite.getGlobalBounds().left << std::endl;
    if (sprite.getGlobalBounds().top < 0.0 || sprite.getGlobalBounds().top > (float) windowHeight){
        active = false; // Balloon out of frame => delete it
    } else {
        sprite.move(0.f, balloonconstants.ypos * time);
    }
    window -> draw(sprite);
}

bool Balloon::isActive(){
        return active;
    }

