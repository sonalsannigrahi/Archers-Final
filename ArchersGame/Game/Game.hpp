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
#include "../Text/text.hpp"
#include "../Setting/Setting.hpp"
#include "../Opponent/Opponent.hpp"
#include "../Opponent/Spear.hpp"
#include "../Opponent/StaticOpponent.hpp"
#include "../Arrow/Arrow.hpp"
#include "../EndGame/EndGame.hpp"
#include "../Encryption/Encryption.hpp"

#include "../ARCADE_ARCHER/STATES.hpp"


class Game {
    private:
        //Username
        sf::String UserName;
        // Encryption
        Encrypt* enc = new Encrypt();

        // Add constants to the class
        GameConstants gameConstants = GameConstants(enc);

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
        Texts text;
        bool isMouseDown = false;
        Setting gameSetting = Setting();
        std::vector<Opponent*> opponent;
        std::vector<Spear*> spear;  
        std::vector<StaticOpponent*> staticOpponent; 
        Player* player = new Player(&opponent, &spear, &staticOpponent, &text);
                 
        //Arrow arrow = Arrow(); // Test arrow
        EndGame endgame = EndGame();

        // Elapsed time
        clock_t elapsedTime;

        // Game Window
        sf::RenderWindow* window;
        
        // A circle
        // sf::CircleShape* circle;

        bool isGamePaused = false;
        int score = 0;
    
        //score viewer
        sf::Text ScoreView;

        // Spawning opponents
        void createOpponent();
        void removeOpponent(int id);
        void createSpear();  
        void removeSpear(int id); 
        void createStaticOpponent(); 
        void removeStaticOpponent(int id); 

    public:
    
        Game();
        ~Game();

        void StartGame();
        void UpdateFrame();
        void GameOver();

        sf::RenderWindow* getWindow();

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

        void setBirdsRate(float rate);
        void setBalloonsRate(float rate);
        void setFireworksRate(float rate);
        void setLightningRate(float rate);

        float getBirdsRate();
        float getBalloonsRate();
        float getFireworksRate();
        float getLightningRate();

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

        void pauseGame();
        void unpauseGame();
        bool getIsGamePaused();
    
        sf::Font font;
};
