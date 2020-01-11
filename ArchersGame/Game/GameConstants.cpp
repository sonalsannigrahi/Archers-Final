#include "../Encryption/Encryption.hpp"
#include <string>

class GameConstants{
    public:
        bool isrunning = false;
    // Window setting
        /**
        
        FOR SOME TIME
        
        int WINDOW_HEIGHT = 1000;
        int WINDOW_WIDTH = 1900;
        **/
        int WINDOW_HEIGHT = 600;
        int WINDOW_WIDTH = 800;
    
        
    // Neutral spawning rate
        float birdRate = 12.5;
        float balloonRate = 15.0;
        float fireworkRate = 1.0;
    // Game setting
        bool isRunning = false;
        bool isRaining = false;
        bool isLightning = false;
        bool isBirds = true;
        bool isPlayer = false;
        bool isBalloon = false;
        bool isFireworks = false;
        bool isBlackhole = true;
        bool isOpponent = false;
        bool isSpear = false;
        bool isStatic = false;
    // Volume
        float masterVolume = 0.0;
        float rainVolume = 0.0;
        float thunderVolume = 0.0;
        float birdsVolume = 0.0;
        float fireworksVolume = 0.0;
        float backgroundVolume = 0.0;
    // Opponent spawn rate
        float opponentRate = 5.0;
        float opponentRateOrigin = 5.0;
        float opponentRateDecay = 0.01;
        float staticOpponentRate = 10.0;
        float staticOpponentRateOrigin = 10.0;
        float staticOpponentRateDecay = 0.02;
        float spearRate = 30.0;
        float spearRateOrigin = 30.0;
        float spearRateDecay = 0.03;
    // Best score
        string BestPlayer = "VisNic";
        int BestScore = 0;
    
    //font
        std::string filename  = "Game/asset/font.TTF";

    GameConstants(Encrypt* enc){
        BestPlayer = enc -> get_item_string("BestPlayer");
        BestScore = enc -> get_item<int>("BestScore");
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
