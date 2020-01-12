#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class EndGame{
private:
    sf::RenderWindow* window;
    sf::Sprite* defback = new sf::Sprite();
    sf::Sprite* defeat = new sf::Sprite();
    sf::Sprite* gameover = new sf::Sprite();
    int windowWidth;
    int windowHeight;
public:
    
    EndGame();
    sf::Sprite* replay = new sf::Sprite();
    sf::Sprite* exit = new sf::Sprite();
    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
};
