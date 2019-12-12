//
//  Birds.cpp
//  ArchersGame
//
//  Created by Sunho Hwang on 25/11/2019.
//  Copyright © 2019 Sunho Hwang. All rights reserved.
//

#include "Birds.hpp"


Birds::Birds(){
    srand (time(NULL)); // Randomize with time

    for (int i = 0; i < birdconstant.filenamelen; i++){
        sf::Texture* texture = new sf::Texture();
        texture -> loadFromFile("Birds/Assets/"+ birdconstant.filename[i]);
        sf::Sprite* sprite = new sf::Sprite(*texture);
        birdsSprites.push_back(*sprite);
    }   

    // Add sound
    music.openFromFile("Birds/Assets/" + birdconstant.musicfile);
    music.play();
    music.setLoop(true);
    music.play();
}

void Birds::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Birds::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;
    birdType = rand() % birdconstant.birdTypeCount;
    current = birdconstant.birdlen * birdType;
    direction = rand() % 2;
    if (direction == 0){
        posX = 0.0;
        for (int i = 0; i < birdconstant.filenamelen; i++) 
            birdsSprites[i].setScale(-1.f, 1.f); // Flip the bird
    } else {
        posX = (float) width;
    }
    posY = rand() % ((int) (height * birdconstant.skylimit));
}

void Birds::updateFrame(double time) {
    counter = counter + time;
    if (counter >= birdconstant.changetime ) {
        counter -= birdconstant.changetime;
        current += 1;
        if (current >= birdconstant.birdlen * (birdType + 1)) 
            current = birdconstant.birdlen * birdType;
    }
    
    //std::cout << "Yo i was here" << std::endl;
    if (direction == 0){
        posX += birdconstant.birdSpeed * time;
    } else {
        posX -= birdconstant.birdSpeed * time;
    }
    if (posX < 0.0 || posX > (float) windowWidth){
        alive = false; // The bird has moved out of the game => delete it
        // And stop music
        music.stop();
    } else {
        birdsSprites[current].setPosition(posX, posY);
        window -> draw(birdsSprites[current]);
    }
}

bool Birds::isAlive(){
    return alive;
}

void Birds::change_volume_bird(float volume){
    music.setVolume(volume);
}
