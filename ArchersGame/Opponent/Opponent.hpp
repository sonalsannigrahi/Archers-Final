#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <SFML/Graphics.hpp>
#include "OpponentConstants.cpp"

class Player;

class Opponent{
private:
    CharConstants charconstant = CharConstants();
    sf::RenderWindow* window;
    std::vector<sf::Sprite> oppSprites;
    sf::Sprite* defeat = new sf::Sprite();
    sf::Sprite* defback = new sf::Sprite();
    sf::RectangleShape healthbar;
    sf::RectangleShape hitboxHead, hitboxBody;
    bool isHitboxDrawn = false;

    Player* player;
    double counter = 0;
    int current = 0;
    int direction = 0;
    int windowWidth, windowHeight;
    bool alive = true;
    float posX, posY, comparison;
    float health;
public:
    
    Opponent(Player* player);
    
    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
    bool isAlive();
    float getHealth();

    bool shoot(float x, float y); //will call in arrow class
};
