#pragma once
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "textconstants.cpp"
#include <stdlib.h>
#include "../Game/Game.hpp"

class Texts{
    private:
    sf::RenderWindow* window;
    int windowWidth, windowHeight;
    TextConstants textconstants = TextConstants();
    sf::Text text;
    sf::Text play;
    sf::Text tutorial;
    sf::Text quit;
    sf::Text ChooseUserName;
    sf::Text EnterPress;
    sf::Text scoreview;
    double counter = 0;
    sf::RectangleShape startbutton;
    sf::Sprite Startsprite;
    sf::Sprite Titlesprite;
    sf::RectangleShape box;

    sf::SoundBuffer soundBuffer;
    sf::Sound sound;
    Game game = Game();

    public:
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
