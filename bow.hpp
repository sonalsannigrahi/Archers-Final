#pragma once
#include <ctime>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>
#include <Texture.hpp>


class Player{
private:
    sf::RenderWindow* window;
    std::vector<sf::Sprite> characterSprites;
    int playerWidth, playerHeight, id;
    double timer;


public:
    
    Player();
    
    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
};
