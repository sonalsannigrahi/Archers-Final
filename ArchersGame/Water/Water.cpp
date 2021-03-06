//
//  Water.cpp
//  ArchersGame
//
//  Created by Sunho Hwang on 24/11/2019.
//  Copyright © 2019 Sunho Hwang. All rights reserved.
//

#include "Water.hpp"

Water::Water(){
    for (int i = 0; i < waterconstants.filename_len; i++){
        sf::Texture* waterTexture = new sf::Texture();
        waterTexture -> loadFromFile("Water/asset/"+waterconstants.filename[i]);
        sf::Sprite* waterSprite = new sf::Sprite(*waterTexture);
        waterSprites.push_back(*waterSprite);
    }
}

void Water::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Water::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;
    for (int i = 0; i < waterconstants.filename_len; i++){
        waterSprites[i].setScale((float) width / waterSprites[i].getGlobalBounds().width * waterSprites[i].getScale().x, 
                                waterconstants.heightScale * (float) height / waterSprites[i].getGlobalBounds().height * waterSprites[i].getScale().y);
        waterSprites[i].setPosition(0.0, height - waterSprites[i].getGlobalBounds().height);
    }
}

void Water::updateFrame(double time) {
    counter += time;
    if (counter >= waterconstants.changetimewater){
        counter -= waterconstants.changetimewater;
        current ++;
        if (current == waterconstants.filename_len){
            current = 0;
        }
    }
    //std::cout << "Yo i was here" << std::endl;
    window -> draw(waterSprites[current]);
}
