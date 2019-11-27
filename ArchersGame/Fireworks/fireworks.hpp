#pragma once
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "WaterConstants.cpp"

class Water{
private:
    sf::RenderWindow* window;
    WaterConstants waterconstants = WaterConstants();
    double counter = 0;
    int current = 0;
    
public:
    
    Water(){
    }
    
    void setWindow(sf::RenderWindow* gameWindow);
    void updateFrame(double time);
};
