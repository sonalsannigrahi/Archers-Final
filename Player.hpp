#pragma once
#include <ctime>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>
#include <ArchersGame/Ground/Ground.hpp>


class Player{
private:
    sf::RenderWindow* window;
    std::vector<sf::Sprite> characterSprites;
    sf::Sprite* sprite = new sf::Sprite();
    sf::Sprite* spritem = new sf::Sprite();
    int playerWidth, playerHeight;
    double timer;
    Ground* ground_p;
    int id;


public:
    
    Player();
    
    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
    void setGround(Ground* ground_p);
};
