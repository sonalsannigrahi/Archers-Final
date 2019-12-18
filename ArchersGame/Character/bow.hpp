#pragma once
#include <ctime>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>


class Player{
private:
    sf::RenderWindow* window;
    std::vector<sf::Sprite> characterSprites;
    sf::Sprite* spriteh = new sf::Sprite();
    sf::Sprite* spriteb = new sf::Sprite();
    sf::Sprite* spritea = new sf::Sprite();
    sf::Sprite* spriteo = new sf::Sprite();
    int playerWidth, playerHeight, id;
    double timer;
    int counter = 0;


public:
    
    Player();
    
    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
};
