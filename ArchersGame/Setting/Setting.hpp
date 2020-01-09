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
    sf::RectangleShape* settingScreen = new sf::RectangleShape();
    Game* game;
    int windowWidth;
    int windowHeight;
    bool isMouseDown = false;

    sf::Font font;

    sf::Text title;
    sf::Text resolution, background;
    sf::Text birds, rain, lightning, fireworks, balloons;
    sf::Text volumeMaster, volumeMusic, volumeGame; 

    sf::Text resChoices[4];

    sf::Sprite* backgroundPreviews[10];
public:
    
    Setting();
    
    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void setGame(Game* game);
    void updateFrame(double time);

};