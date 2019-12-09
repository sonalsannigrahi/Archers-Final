//
//  Birds.hpp
//  ArchersGame
//
//  Created by Sunho Hwang on 25/11/2019.
//  Copyright © 2019 Sunho Hwang. All rights reserved.
//

#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "BirdsConstants.cpp"

class Birds{
private:
    BirdsConstants birdconstant = BirdsConstants();
    sf::RenderWindow* window;
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;
    std::vector<sf::Sprite> birdsSprites;
    double counter = 0;
    int current = 0;
    int birdType;
    int direction;
    int windowWidth, windowHeight;
    bool alive = true;
    float posX, posY;
public:
    
    Birds();
    
    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
    bool isAlive();
};
