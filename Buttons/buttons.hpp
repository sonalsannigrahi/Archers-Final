#pragma once

#include <ctime>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "ButtonsConstants.cpp"

class Buttons{
private:
    sf::RenderWindow* window;
    ButtonsConstants buttonsconstants = ButtonsConstants();
    sf::Sprite sprite;
    int windowWidth, windowHeight;
    bool active = true;
    bool isButtonClicked(sf::)
    bool loadgame();

public:
    
    Buttons();
    
    void setSize(int width, int height);
    bool isActive();
    void setWindow(sf::RenderWindow* gameWindow);
    void updateFrame(double time);
    bool isButtonClicked(sf::sprite sprite);
    virtual void handleInput();
};

