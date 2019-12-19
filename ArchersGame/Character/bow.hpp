#pragma once
#include <ctime>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>
#include "../Arrow/Arrow.hpp"


class Player{
private:
    sf::RenderWindow* window;
    std::vector<sf::Sprite> characterSprites;
    sf::Sprite* spriteh = new sf::Sprite();
    sf::Sprite* spriteb = new sf::Sprite();

    int winWidth, winHeight;
    double timer;
    int counter = 0;
    float lastAngle;

public:
    
    Player();
    
    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
};
