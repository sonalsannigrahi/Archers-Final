#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SettingConstants.cpp"

class Game;

class Setting{
private:
    SettingConstants settingConstants = SettingConstants();
    sf::RenderWindow* window;
    sf::Sprite* settingButton;
    Game* game;
    int windowWidth;
    int windowHeight;
public:
    
    Setting();
    
    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void setGame(Game* game);
    void updateFrame(double time);

};