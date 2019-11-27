//
//  Water.cpp
//  ArchersGame
//
//  Created by Sunho Hwang on 24/11/2019.
//  Copyright © 2019 Sunho Hwang. All rights reserved.
//

#include "Water.hpp"

void Water::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Water::updateFrame(double time) {
    counter += time;
    if (counter >= waterconstants.changetimewater){
        counter = 0;
        current ++;
        if (current == waterconstants.filename_len){
            current = 0;
        }
    }
     sf::Texture texture;
    texture.loadFromFile("Water/asset/"+waterconstants.filename[current]);
    //std::cout << "Yo i was here" << std::endl;
    sf::Sprite sprite(texture);
    window -> draw(sprite);
}
