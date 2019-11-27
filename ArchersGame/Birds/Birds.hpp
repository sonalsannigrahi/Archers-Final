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
#include <SFML/Graphics.hpp>
#include "BirdsConstants.cpp"

class Birds{
private:
    BirdsConstants birdconstant = BirdsConstants();
    sf::RenderWindow* window;
    double counter = 0;
    int current = 0;
public:
    
    Birds(){
    }
    
    void setWindow(sf::RenderWindow* gameWindow);
    void updateFrame(double time);
};
