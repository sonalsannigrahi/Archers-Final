#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>

#include <../Menu/Menu.hpp>
#include "GameConstants.cpp"
#include "GameFPS.cpp"
#include "../Game/Game.hpp"
#include "../Background/Background.hpp"
#include "../Water/Water.hpp"
#include "../Birds/Birds.hpp"
#include "../Lightning/Lightning.hpp"
#include "../Rain/Rain.hpp"
#include "../Balloon/Balloon.hpp"
#include "../Fireworks/fireworks.hpp"

class StartScreen {
    private:
        GameFPS gameFPS = GameFPS();
        Background gameBackground = Background();
        // Elapsed time
        clock_t elapsedTime;
        // Game Window
        sf::RenderWindow* window;
        // A circle
        sf::CircleShape* circle;

    public:
        StartScreen();
        ~StartScreen();
        void Settings();
        void Star();
        void Endless();
        void Campaign();
        void UpdateFrame();
};
