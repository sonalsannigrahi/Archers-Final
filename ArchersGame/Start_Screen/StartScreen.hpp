#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "StartScreenConstants.cpp"
class StartScreen {
    private:
        // Add constants to the class
        StartScreenConstants startScreenConstants = StartScreenConstants();
        // All other classes
        // Elapsed time
        clock_t elapsedTime;
        sf::Sprite startScreenSprite;
        // Game Window
        sf::RenderWindow* window;
        int backgroundWidth;
        int backgroundHeight;
        // A circle
        // sf::CircleShape* circle;

    public:

        StartScreen();
        ~StartScreen();
        void run();
        void setWindow(sf::RenderWindow* gameWindow);
        void setSize(int width, int height);
        void UpdateFrame(double time);
};
