#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <SFML/Graphics.hpp>
#include "StaticConstants.cpp"
#include "../Arrow/Arrow.hpp"

class Player;
class Opponent;
class Spear;
class Texts;

class StaticOpponent{
private:
    StaticConstants statconstant = StaticConstants();
    sf::RenderWindow* window;
    std::vector<sf::Sprite> statSprites;
    sf::Sprite* spriteh = new sf::Sprite();
    sf::Sprite* defeat = new sf::Sprite();
    sf::Sprite* defback = new sf::Sprite();
    //sf::Sprite* headshot = new sf::Sprite();
    sf::RectangleShape hitboxHead, hitboxBody;
    sf::RectangleShape healthbar;
    bool isHitboxDrawn = false;

    Player* player;
    std::vector<Opponent*>* opponent = new std::vector<Opponent*>();
    std::vector<Spear*>* spear = new std::vector<Spear*>();
    std::vector<StaticOpponent*>* statOpponent = new std::vector<StaticOpponent*>();
    Texts* text;
    std::vector<Arrow*> arrows;
    double counter = 0;
    float health;
    int current = 0;
    int windowWidth, windowHeight;
    bool alive = true;
    float posX, posY;
public:

    StaticOpponent(Player* player, Texts* text);

    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
    bool isAlive();
    float getHealth();
    bool shoot(float X, float Y); //will call in arrow class

    void createArrow(float posX, float posY, float vX, float vY);
    void removeArrow(int id);
};
