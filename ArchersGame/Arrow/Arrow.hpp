#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ArrowConstants.cpp"

class Arrow{
private:
    ArrowConstants arrowConstants = ArrowConstants();
    sf::RenderWindow* window;
    sf::Sprite* arrowSprite;
    
    int windowWidth, windowHeight;
    bool alive = true;
    
    float posX, posY, vX, vY;
    float angle;

public:
    
    Arrow();
    Arrow(float posX, float posY, float vX, float vY);

    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
    bool isAlive();
};