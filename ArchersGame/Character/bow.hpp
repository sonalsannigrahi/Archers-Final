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

class Player{
private:
    sf::RenderWindow* window;
    std::vector<sf::Sprite> characterSprites;
    sf::Sprite* spriteh = new sf::Sprite();
    sf::Sprite* spriteb = new sf::Sprite();
    std::vector<Arrow*> arrows;

    sf::RectangleShape hitboxHead, hitboxBody;
    bool isHitboxDrawn = true;

    int winWidth, winHeight;
    double timer;
    int counter = 0;
    float lastAngle;

    float maxHealth = 100.f;
    float health;
    Texts* texts;
    std::vector<Opponent*>* opponent;

public:
    
    Player(std::vector<Opponent*>* opponent,Texts* texts);
    
    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);

    void createArrow(float posX, float posY, float vX, float vY);
    void removeArrow(int id);

    bool shoot(float x, float y);
    void stab();

    float getHealth();
    void resetHealth();
};
