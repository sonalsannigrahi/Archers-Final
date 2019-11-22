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
    sf::RenderWindow* window;
public:
    Background(sf::RenderWindow* gameWindow){
        window = gameWindow;
    }
    
    void updateFrame(double time);
};
