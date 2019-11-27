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

class Balloon{
private:
    sf::RenderWindow* window;
public:
    
    Balloon(){
    }
    
    void setWindow(sf::RenderWindow* gameWindow);
    void updateFrame(double time);
};
