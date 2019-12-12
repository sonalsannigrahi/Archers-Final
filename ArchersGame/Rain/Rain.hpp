#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "RainConstants.cpp"
#include <SFML/Audio.hpp>

class Rain{
private:
    sf::RenderWindow* window;
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;
    RainConstants rainConstants = RainConstants();
    std::vector<sf::Sprite> rainSprite;
    int rainWidth;
    int rainHeight;
    double timer = 0.0;
    int current = 0;
public:
    
    Rain();
    
    void setWindow(sf::RenderWindow* gameWindow);
    void setSize(int width, int height);
    void updateFrame(double time);
<<<<<<< HEAD
    void change_volume_rain(int volume);
=======
    void playAudio();
    void stopAudio();
>>>>>>> Game-Design---Minh-Tuan
};
