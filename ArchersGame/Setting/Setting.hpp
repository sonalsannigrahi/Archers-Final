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
    bool isMouseDown2[5];

    sf::Font font, roboto_font;

    sf::Text title;
    sf::Text resolution, background;
    sf::Text birds, rain, lightning, fireworks, balloons;
    sf::Text volumeMaster, volumeMusic, volumeGame; 
    sf::Text volumeMasterValue, volumeMusicValue, volumeGameValue;
    sf::Sprite* objChoices[5];
    sf::Text resChoices[4];
    sf::Sprite* backgroundPreviews[10];
    sf::RectangleShape* volumeSlide[3];
    sf::CircleShape* volumeButton[3];
public:
    
    Setting();
    
    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void setGame(Game* game);
    void updateFrame(double time);

};