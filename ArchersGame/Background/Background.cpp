//
//  Background.cpp
//  ArchersGame
//
//  Created by Sunho Hwang on 22/11/2019.
//  Copyright © 2019 Sunho Hwang. All rights reserved.
//

#include "Background.hpp"

Background::Background(){
    for (int i = 0; i < backgroundConstants.filename_length; i++){
        sf::Texture* texture = new sf::Texture();
        texture -> loadFromFile("Background/Asset/" + backgroundConstants.filename[i]);
        sf::Sprite* sprite = new sf::Sprite(*texture);
        backgroundSprites.push_back(*sprite);
    }
    // Add sound
    soundBuffer.loadFromFile("Background/Asset/" + backgroundConstants.musicfile);
    sound.setBuffer(soundBuffer);
    sound.setLoop(true);
    sound.play();
}

void Background::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Background::setSize(int width, int height){
    backgroundWidth = width;
    backgroundHeight = height;
    for (int i = 0; i < backgroundConstants.filename_length; i++)
        backgroundSprites[i].setScale((float) width / backgroundSprites[i].getGlobalBounds().width, (float) height / backgroundSprites[i].getGlobalBounds().height);
}

void Background::updateFrame(double time) {
    //std::cout << "Yo i was here" << std::endl;
    window -> draw(backgroundSprites[backgroundConstants.chosen]);
}
