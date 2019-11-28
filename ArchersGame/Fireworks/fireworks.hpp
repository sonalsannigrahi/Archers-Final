#pragma once
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "fireworksconstants.cpp"

class Fireworks{
private:
    sf::RenderWindow* window;
    FireworksConstants fireworksconstants = FireworksConstants();
    double counter = 0;
    int current = 0;
    
public:
    
    Fireworks(){
    }
    
    void setWindow(sf::RenderWindow* gameWindow);
    void updateFrame(double time);
};
