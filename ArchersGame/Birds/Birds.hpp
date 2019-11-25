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
    sf::RenderWindow* window;
public:
    
    Birds(){
    }
    
    void setWindow(sf::RenderWindow* gameWindow);
    void updateFrame(double time);
};
