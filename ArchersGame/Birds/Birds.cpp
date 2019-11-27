//
//  Birds.cpp
//  ArchersGame
//
//  Created by Sunho Hwang on 25/11/2019.
//  Copyright © 2019 Sunho Hwang. All rights reserved.
//

#include "Birds.hpp"

void Birds::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Birds::updateFrame(double time) {
    counter = counter + time;
    if (counter >= birdconstant.changetime ) {
        counter = 0;
        current +=1;
        if (current >= birdconstant.filenamelen) current = 0;
    }
    sf::Texture texture;
    texture.loadFromFile("Birds/Assets/"+ birdconstant.filename[current]);
    //std::cout << "Yo i was here" << std::endl;
    sf::Sprite sprite(texture);
    window -> draw(sprite);
    
    
    
}
