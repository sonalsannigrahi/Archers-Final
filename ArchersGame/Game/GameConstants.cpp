class GameConstants{
    public:
    // Window setting
        int WINDOW_HEIGHT = 720;
        int WINDOW_WIDTH = 1240;
    // Spawning rate
        int birdRate = 1200;
        int balloonRate = 2000;
        int fireworkRate = 500;
    // Game setting
        bool isRaining = false;
        bool isLightning = false;
        bool isBirds = true;
        bool isBalloon = false;
        bool isFireworks = true;
        bool isBlackhole = false;
    // Volume
        float masterVolume = 100.0;
        float rainVolume = 100.0;
        float thunderVolume = 100.0;
        float birdsVolume = 100.0;
        float fireworksVolume = 100.0;
        float backgroundVolume = 100.0;
};
