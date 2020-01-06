#include "../Encryption/Encryption.hpp"
#include <string>

class GameConstants{
    public:
        bool isrunning = false;
    // Window setting
        int WINDOW_HEIGHT = 600;
        int WINDOW_WIDTH = 900;
    // Neutral spawning rate
        float birdRate = 2.5;
        float balloonRate = 5.0;
        float fireworkRate = 0.5;
    // Game setting
        bool isRunning = false;
        bool isRaining = false;
        bool isLightning = false;
        bool isBirds = true;
        bool isPlayer = false;
        bool isBalloon = false;
        bool isFireworks = false;
        bool isBlackhole = false;
        bool isOpponent = false;
    // Volume
        float masterVolume = 100.0;
        float rainVolume = 100.0;
        float thunderVolume = 100.0;
        float birdsVolume = 100.0;
        float fireworksVolume = 100.0;
        float backgroundVolume = 100.0;
    // Opponent spawn rate
        float opponentRate = 1.0;
        float staticOpponentRate = 25.0;
        float spearRate = 60.0;

    GameConstants(Encrypt* enc){
        WINDOW_HEIGHT = enc -> get_item<int>("WINDOW_HEIGHT");
        WINDOW_WIDTH = enc -> get_item<int>("WINDOW_WIDTH");
        isRaining = (enc -> get_item<int>("isRaining") == 1);
        isLightning = (enc -> get_item<int>("isLightning") == 1);
        isBirds = (enc -> get_item<int>("isBirds") == 1);
        isBalloon = (enc -> get_item<int>("isBalloon") == 1);
        isFireworks = (enc -> get_item<int>("isFireworks") == 1);
        isBlackhole = (enc -> get_item<int>("isBlackhole") == 1);
        masterVolume = enc -> get_item<float>("masterVolume");
        rainVolume = enc -> get_item<float>("rainVolume");
        thunderVolume = enc -> get_item<float>("thunderVolume");
        birdsVolume = enc -> get_item<float>("birdsVolume");
        fireworksVolume = enc -> get_item<float>("fireworksVolume");    
        backgroundVolume = enc -> get_item<float>("backgroundVolume");
    }
};
