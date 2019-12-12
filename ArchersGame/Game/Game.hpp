#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "GameConstants.cpp"
#include "GameFPS.cpp"
#include "../Background/Background.hpp"
#include "../Water/Water.hpp"
#include "../Birds/Birds.hpp"
#include "../Lightning/Lightning.hpp"
#include "../Rain/Rain.hpp"
#include "../Balloon/Balloon.hpp"
#include "../Fireworks/fireworks.hpp"
#include "../Character/bow.hpp"

class Game {
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
        Player player = Player();

        // Elapsed time
        clock_t elapsedTime;

        // Game Window
        sf::RenderWindow* window;
        // A circle
        // sf::CircleShape* circle;

        bool isGamePaused = false;

    public:
    
        Game();
        ~Game();

        void StartGame();
        void UpdateFrame();
        void EndGame();

        void createBird();
        void removeBird(int id);
        void createBalloon();
        void removeBalloon(int id);
        void createFireworks();
        void removeFireworks(int id);

        void toggleBirds();
        void toggleRain();
        void toggleLightning();
        void toggleBalloons();
        void toggleFireworks();
        void toggleBlackhole();

        bool getIsBirds();
        bool getIsRaining();
        bool getIsLightning();
        bool getIsBalloons();
        bool getIsFireworks();
        bool getIsBlackhole();

        void setBirdsRate(int rate);
        void setBalloonsRate(int rate);
        void setFireworksRate(int rate);
        void setLightningRate(int rate);

        int getBirdsRate();
        int getBalloonsRate();
        int getFireworksRate();
        int getLightningRate();

        float getMasterVolume();
        float getBackgroundVolume();
        float getRainVolume();
        float getThunderVolume();
        float getBirdsVolume();
        float getFireworksVolume();

        void setMasterVolume(float volume);
        void setBackgroundVolume(float volume);
        void setRainVolume(float volume);
        void setThunderVolume(float volume);
        void setBirdsVolume(float volume);
        void setFireworksVolume(float volume);
    
        void changeBackgroundPicture(int chosen);

        void setWindowSize(int width, int height);
};
