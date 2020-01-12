#pragma once
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "textconstants.cpp"
#include <stdlib.h> 
#include "../ARCADE_ARCHER/RETRO_GAME.hpp"
#include "../ARCADE_ARCHER/RETRO_GAME_SETTINGS.hpp"

class Texts{
    private:
    sf::RenderWindow* window;
    int windowWidth, windowHeight;
    sf::Text text;
    sf::Text play;
    sf::Text tutorial;
    sf::Text BestScore;
    sf::Text quit;
    sf::Text retro;
    sf::Text ChooseUserName;
    sf::Text HighestScore;
    double counter = 0;
    sf::RectangleShape startbutton;
    sf::Sprite Startsprite;
    sf::Sprite Titlesprite;
    sf::Sprite Titlesprite1;
    sf::RectangleShape box;
    sf::Text PressEnter;

    sf::SoundBuffer soundBuffer;
    sf::Sound sound;

    public:
    TextConstants textconstants = TextConstants();
    sf::Font font;
    void loadgame();
    int bruh;
    Texts();
    bool loadgame(float x, float y);
    bool box_hit(float x,float y);
    void setposition(float x, float y);
    void setsize(int px);
    void setWindow(sf::RenderWindow* gameWindow);
    void setWindowSize(int width, int height);
    void updateFrame(double time);
    void setstring(std::string txt);
    void put_text_button(sf::RectangleShape button);
};