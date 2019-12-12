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
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "BackgroundConstants.cpp"

class Background{
private:
    BackgroundConstants backgroundConstants = BackgroundConstants();
    sf::RenderWindow* window;
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;
    std::vector<sf::Sprite> backgroundSprites;
    int backgroundWidth;
    int backgroundHeight;
public:
    
    Background();
    
    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
};
