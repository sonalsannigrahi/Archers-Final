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
        // Add constants to the class
        GameConstants gameConstants = GameConstants();

        // All other classes
        // ...
        GameFPS gameFPS = GameFPS();
        Background gameBackground = Background();
        Water gameWater = Water();
        Lightning gameLightning = Lightning();
        Rain gameRain = Rain();
        std::vector<Birds*> birds;
        std::vector<Balloon*> balloons;
        std::vector<Fireworks*> fireworks;
        //Button startButton = Button("start");
        //Button settingsButton = Button("settings");
        //Button infoButton = Button("info");
        //Button exitGame = Button("exit");
        Menu menu;
        // Elapsed time
        clock_t elapsedTime;

        // Game Window
        sf::RenderWindow* window;
        // A circle
        sf::CircleShape* circle;

    public:

        StartScreen();
        ~StartScreen();
        void Start();
        void NewGame();
        //void PlayerMode();
        void UpdateFrame();
        void createBird();
        void removeBird(int id);
        void createBalloon();
        void removeBalloon(int id);
        void createFireworks();
        void removeFireworks(int id);
};
