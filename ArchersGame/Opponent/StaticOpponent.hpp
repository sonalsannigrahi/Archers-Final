#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <SFML/Graphics.hpp>
#include "StaticConstants.cpp"

class Player;

class StaticOpponent{
private:
    StaticConstants statconstant = StaticConstants();
    sf::RenderWindow* window;
    std::vector<sf::Sprite> statSprites;
    sf::Sprite* defeat = new sf::Sprite();
    sf::Sprite* defback = new sf::Sprite();
    //sf::Sprite* headshot = new sf::Sprite();
    sf::RectangleShape hitboxHead, hitboxBody;
    sf::RectangleShape healthbar;
    bool isHitboxDrawn = true;

    Player* player;
    double counter = 0;
    float health;
    int current = 0;
    int windowWidth, windowHeight;
    bool alive = true;
    float posX, posY;
public:

    StaticOpponent(Player* player);

    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
    bool isAlive();
    bool shoot(float X, float Y); //will call in arrow class
};
