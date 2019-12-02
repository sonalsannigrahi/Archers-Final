#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "RainConstants.cpp"

class Rain{
private:
    sf::RenderWindow* window;
    RainConstants rainConstants = RainConstants();
    std::vector<sf::Sprite> rainSprite;
    int rainWidth;
    int rainHeight;
    double timer = 0.0;
    int current = 0;
public:
    
    Rain();
    
    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
};
