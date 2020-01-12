#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <SFML/Graphics.hpp>
#include "SpearConstants.cpp"
#include "../Arrow/Arrow.hpp"

class Player;
class Opponent;
class StaticOpponent;
class Texts;


class Spear{
private:
    SpearConstants spearconstant = SpearConstants();
    sf::RenderWindow* window;
    std::vector<sf::Sprite> spearSprites;
    sf::Sprite* defeat = new sf::Sprite();
    sf::Sprite* defback = new sf::Sprite();
    sf::RectangleShape hitboxHead, hitboxBody;
    sf::RectangleShape healthbar;

    bool isHitboxDrawn = false;

    Player* player;   
    std::vector<Opponent*>* opponent = new std::vector<Opponent*>();
    std::vector<Spear*>* spear = new std::vector<Spear*>();
    std::vector<StaticOpponent*>* statOpponent = new std::vector<StaticOpponent*>();
    Texts* text;
    std::string filename;
    float scale;
    std::vector<Arrow*> arrows;
    double counter = 0;
    int current = 0;
    int windowWidth, windowHeight;
    bool alive = true;
    float health;
    float posX, posY;
public:

    Spear(Player* player, Texts* texts);

    void setWindow(sf::RenderWindow* gameWindow);
    void createArrow(float posX, float posY, float vX, float vY);
    void removeArrow(int id);
    void setSize(int width, int height);
    void updateFrame(double time);
    bool isAlive();
    float getHealth();
    bool shoot(float X, float Y); //will call in arrow class
};
