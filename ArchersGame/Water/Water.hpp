//
//  Water.hpp
//  ArchersGame
//
//  Created by Sunho Hwang on 24/11/2019.
//  Copyright © 2019 Sunho Hwang. All rights reserved.
//

#pragma once
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "WaterConstants.cpp"

class Water{
private:
    sf::RenderWindow* window;
public:
    
    Water(){
    }
    
    void setWindow(sf::RenderWindow* gameWindow);
    void updateFrame(double time);
};
