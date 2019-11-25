#pragma once
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameConstants.cpp"
#include "GameFPS.cpp"
#include "../Background/Background.hpp"

class Game {
    private:
        // Add constants to the class
        GameConstants gameConstants = GameConstants();
        GameFPS gameFPS = GameFPS();
        Background gameBackground = Background();

        // All other classes
        // ...

        // Elapsed time
        clock_t elapsedTime;

        // Game Window
        sf::RenderWindow* window;
        // A circle
        sf::CircleShape* circle;

    public:
    
        Game();
        ~Game();

        void StartGame();
        void UpdateFrame();
        void EndGame();
};
