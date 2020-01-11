#pragma once
#include <ctime>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>
#include "../Arrow/Arrow.hpp"
#include "../Text/text.hpp"
class Opponent;
class Spear;
class StaticOpponent;

class Player{
private:
    sf::RenderWindow* window;
    std::vector<sf::Sprite> characterSprites;
    sf::Sprite* spriteh = new sf::Sprite();
    sf::Sprite* spriteb = new sf::Sprite();
    std::vector<Arrow*> arrows;

    sf::RectangleShape hitboxHead, hitboxBody;
    bool isHitboxDrawn = false;

    int winWidth, winHeight;
    double timer;
    int counter = 0;
    float lastAngle;
    double lastPower = 0;

    float maxHealth = 100.f;
    sf::RectangleShape healthbar;
    float health;
    Texts* texts;
    std::string filename;
    std::vector<Opponent*>* opponent;
    std::vector<Spear*>* spear;
    std::vector<StaticOpponent*>* statico;

public:
    
    Player(std::vector<Opponent*>* opponent, std::vector<Spear*>* spear,  std::vector<StaticOpponent*>* statico, Texts* texts);
    
    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);

    void createArrow(float posX, float posY, float vX, float vY);
    void removeArrow(int id);

    bool shoot(float x, float y);
    void stab();
    void pierced(float x, float y);

    float getHealth();
    void resetHealth();
};
