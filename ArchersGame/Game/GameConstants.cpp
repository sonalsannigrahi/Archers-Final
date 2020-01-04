#include "../Encryption/Encryption.hpp"

class GameConstants{
    public:
        bool isrunning = false;
    // Window setting
        int WINDOW_HEIGHT;
        int WINDOW_WIDTH;
    // Neutral spawning rate
        float birdRate = 0.5;
        float balloonRate = 5.0;
        float fireworkRate = 0.5;
    // Game setting

        bool isRunning = false;
        bool isRaining = true;
        bool isLightning = true;
        bool isBirds = true;
        bool isPlayer = false;
        bool isBalloon = true;
        bool isFireworks = true;
        bool isBlackhole = true;
        bool isOpponent = false;

    // Volume
        float masterVolume;
        float rainVolume;
        float thunderVolume;
        float birdsVolume;
        float fireworksVolume;
        float backgroundVolume;
    // Opponent spawn rate
        float opponentRate = 1.0;
        float staticOpponentRate = 25.0;
        float spearRate = 60.0;

    GameConstants(){
        Encrypt* enc = new Encrypt();
        
        WINDOW_HEIGHT = enc -> get_item<int>("WINDOW_HEIGHT");
        WINDOW_WIDTH = enc -> get_item<int>("WINDOW_WIDTH");

        isRaining = (enc -> get_item<int>("isRaining") != 0);
        isLightning = (enc -> get_item<int>("isLightning") != 0);
        isBirds = (enc -> get_item<int>("isBirds") != 0);
        isBalloon = (enc -> get_item<int>("isBalloon") != 0);
        isFireworks = (enc -> get_item<int>("isFireworks") != 0);
        isBlackhole = (enc -> get_item<int>("isBlackhole") != 0);

        masterVolume = enc -> get_item<float>("masterVolume");
        rainVolume = enc -> get_item<float>("rainVolume");
        thunderVolume = enc -> get_item<float>("thunderVolume");
        birdsVolume = enc -> get_item<float>("birdsVolume");
        fireworksVolume = enc -> get_item<float>("fireworksVolume");
        backgroundVolume = enc -> get_item<float>("backgroundVolume");
    }
};
