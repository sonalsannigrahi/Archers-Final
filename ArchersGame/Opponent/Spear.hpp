#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <SFML/Graphics.hpp>
#include "SpearConstants.cpp"

class Player;

class Spear{
private:
    SpearConstants spearconstant = SpearConstants();
    sf::RenderWindow* window;
    std::vector<sf::Sprite> spearSprites;
    sf::Sprite* defeat = new sf::Sprite();
    sf::Sprite* defback = new sf::Sprite();

    Player* player;
    double counter = 0;
    int current = 0;
    int windowWidth, windowHeight;
    bool alive = true;
    float posX, posY;
public:

    Spear(Player* player);

    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
    bool isAlive();
    bool isShot(float X, float Y); //will call in arrow class
};
