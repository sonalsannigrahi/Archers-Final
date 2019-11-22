//
//  Background.hpp
//  ArchersGame
//
//  Created by Sunho Hwang on 22/11/2019.
//  Copyright © 2019 Sunho Hwang. All rights reserved.
//

#pragma once
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "BackgroundConstants.cpp"

class Background{
private:
public:
    sf::RenderWindow* window;
    
    Background(){
    }
    
    void updateFrame(double time);
};
