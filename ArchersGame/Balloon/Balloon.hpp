//
//  Balloon.hpp
//  ArchersGame
//
//  Created by Sunho Hwang on 27/11/2019.
//  Copyright © 2019 Sunho Hwang. All rights reserved.
//


#pragma once
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "BalloonConstants.cpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>  

class Balloon{
private:
    BalloonConstants balloonconstants = BalloonConstants();
    sf::RenderWindow* window;
    sf::Sprite sprite;
    int windowWidth, windowHeight;
    bool active = true;
    float posY;
public:
    
    Balloon();
    
    void setSize(int width, int height);
    bool isActive();
    void setWindow(sf::RenderWindow* gameWindow);
    void updateFrame(double time);
};
