#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "BlackholeConstants.cpp"

class Blackhole{
  private:
    sf::RenderWindow* window;
    BlackholeConstants blackholeConstants = BlackholeConstants();
    std::vector<sf::Sprite> blackholeSprites;
    int blackholeWidth, blackholeHeight, id;
    double counter = 0;
    int current = 0;
  public:

    Blackhole();

    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
    void setBlackholePosition(float x, float y);

};
