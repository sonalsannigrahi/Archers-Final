#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "LightningConstants.cpp"

class Lightning{
private:
    sf::RenderWindow* window;
    LightningConstants lightningConstants = LightningConstants();
    std::vector<sf::Sprite> lightningSprites;
    int lightningWidth, lightningHeight, id;
    double timer;
public:
    
    Lightning();
    
    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
};
