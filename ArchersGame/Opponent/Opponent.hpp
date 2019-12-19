#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <SFML/Graphics.hpp>
#include "OpponentConstants.cpp"

class Opponent{
private:
    CharConstants charconstant = CharConstants();
    sf::RenderWindow* window;
    std::vector<sf::Sprite> oppSprites;
    sf::Sprite* defeat = new sf::Sprite();
    sf::Sprite* defback = new sf::Sprite();
    double counter = 0;
    int current = 0;
    int direction = 0;
    int windowWidth, windowHeight;
    bool alive = true;
    float posX, posY, comparison;
public:
    
    Opponent();
    
    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
    bool isAlive();
    bool isShot(float X, float Y); //will call in arrow class
};
