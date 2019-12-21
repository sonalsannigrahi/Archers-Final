#pragma once
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "textconstants.cpp"
#include <stdlib.h> 

class Texts{
    private:
    sf::RenderWindow* window;
    int windowWidth, windowHeight;
    TextConstants textconstants = TextConstants();
    sf::Text text;
    sf::Font font;
    double counter = 0;
    sf::RectangleShape button;
    
    public:
    int bruh;
    Texts();
    bool loadgame(float x, float y);
    void setposition(float x, float y);
    void setsize(int px);
    void setWindow(sf::RenderWindow* gameWindow);
    void setWindowSize(int width, int height);
    void updateFrame(double time);
    void setstring(std::string txt);
};