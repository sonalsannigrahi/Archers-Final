#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ArrowConstants.cpp"
#include "../Text/text.hpp"

class Player;
class Spear;
class Opponent;
class StaticOpponent;

class Arrow{
private:
    ArrowConstants arrowConstants = ArrowConstants();
    sf::RenderWindow* window;
    sf::Sprite* arrowSprite;
    
    Player* player;
    std::vector<Opponent*>* opponent;
    std::vector<Spear*>* spear;
    std::vector<StaticOpponent*>* statico;
    sf::RectangleShape hitbox;
    bool isHitboxDrawn = true;
    
    int windowWidth, windowHeight;
    bool alive = true;
    Texts* texts;
    float posX, posY, vX, vY;
    float angle;

public:
    
    Arrow();
    Arrow(float posX, float posY, float vX, float vY, Player* player, std::vector<Opponent*>* opponent, std::vector<Spear*>* spear,std::vector<StaticOpponent*>* statico, Texts* texts);

    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
    bool isAlive();
};