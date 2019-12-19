#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ArrowConstants.cpp"

class Arrow{
private:
    ArrowConstants arrowConstants = ArrowConstants();
    sf::RenderWindow* window;
    sf::Music music;
    
    int windowWidth, windowHeight;
    bool alive = true;
    float posX, posY;
    float angle;

public:
    
    Birds();
    
    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
    bool isAlive();
    void change_volume_bird(float volume);
};