#include "../Encryption/Encryption.hpp"

class GameConstants{
    public:
        bool isrunning = false;
    // Window setting
        int WINDOW_HEIGHT = 600;
        int WINDOW_WIDTH = 900;
    // Neutral spawning rate
        float birdRate = 0.5;
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
        float masterVolume = 0.0;
        float rainVolume = 100.0;
        float thunderVolume = 100.0;
        float birdsVolume = 100.0;
        float fireworksVolume = 100.0;
        float backgroundVolume = 100.0;
    // Opponent spawn rate
        float opponentRate = 1.0;
        float staticOpponentRate = 25.0;
        float spearRate = 60.0;
};
