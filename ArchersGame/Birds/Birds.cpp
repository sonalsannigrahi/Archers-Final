//
//  Birds.cpp
//  ArchersGame
//
//  Created by Sunho Hwang on 25/11/2019.
//  Copyright © 2019 Sunho Hwang. All rights reserved.
//

#include "Birds.hpp"

Birds::Birds(){
    for (int i = 0; i < birdconstant.filenamelen; i++){
        sf::Texture* texture = new sf::Texture();
        texture -> loadFromFile("Birds/Assets/"+ birdconstant.filename[i]);
        sf::Sprite* sprite = new sf::Sprite(*texture);
        birdsSprites.push_back(*sprite);
    }   
}

void Birds::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Birds::updateFrame(double time) {
    counter = counter + time;
    if (counter >= birdconstant.changetime ) {
        counter = 0;
        current += 1;
        if (current >= birdconstant.birdlen * (birdconstant.birdtype + 1)) 
            current = birdconstant.birdlen * birdconstant.birdtype;
    }
    
    //std::cout << "Yo i was here" << std::endl;
    window -> draw(birdsSprites[current]);
}

bool Birds::isAlive(){
    return alive;
}
