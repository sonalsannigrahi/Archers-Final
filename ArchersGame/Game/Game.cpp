#include "Game.hpp"

Game::Game(){
    srand(time(NULL)); // Randomize
    
    // Create game window
    sf::VideoMode videoMode = sf::VideoMode(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    window = new sf::RenderWindow(videoMode, "Archers");

    // Send window to other classes
    gameBackground.setWindow(window);
    gameWater.setWindow(window);
    gameLightning.setWindow(window);
    gameRain.setWindow(window);

    // Inititalize other variables
    gameBackground.setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    gameWater.setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    gameLightning.setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    gameRain.setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);

    // Start game
    std::cout << "Starting Game ..." << std::endl;
    StartGame();
}

Game::~Game(){
}

void Game::StartGame(){
    // CIRCLE TEST

    // Draw a circle
    // circle = new sf::CircleShape(100.f);
    // circle -> setFillColor(sf::Color::Green);

    // END CIRCLE TEST

    // TEST BIRDS

    // createBird();
    
    // END TEST BIRDS

    // Start timer
    elapsedTime = clock();

    // Update Frame
    std::cout << "Game started ..." << std::endl;
    while (window -> isOpen())
    {
        sf::Event event;
        while (window -> pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window -> close();
        }

        window -> clear();
        UpdateFrame();
        window -> display();
    }
}

void Game::UpdateFrame(){
    // std::cout << "Updating Frame at " << double(elapsedTime) / CLOCKS_PER_SEC << std::endl;

    // Creating birds
    if (rand() % gameConstants.birdRate == 0) createBird();

    // Creating balloons
    if (rand() % gameConstants.balloonRate == 0) createBalloon();

    // Calculate time has passed since the last UpdateFrame
    double time = double(clock() - elapsedTime) / CLOCKS_PER_SEC;
    elapsedTime = clock();
    
    // Draw Background
    gameBackground.updateFrame(time);
    //std::cout << "Yo i was here" << std::endl;

    // Draw Lightning
    if (gameConstants.isLightning) gameLightning.updateFrame(time);

    // Draw birds
    if (gameConstants.isBirds){
        int id = 0;
        while (id < birds.size()){
            if (birds[id] -> isAlive()){
                birds[id] -> updateFrame(time);
                id++;
            }
            else removeBird(id);
        }
    }

    // Draw balloons
    if (gameConstants.isBalloon){
        int id = 0;
        //std::cout << balloons.size();
        while (id < balloons.size()){
            if (balloons[id] -> isActive()){
                balloons[id] -> updateFrame(time);
                id++;
            }
            else removeBalloon(id);
        }
    }

    // Draw Rain
    if (gameConstants.isRaining) gameRain.updateFrame(time);

    // Draw Waters
    gameWater.updateFrame(time);

    // Update FPS counter
    gameFPS.UpdateFPS(double(elapsedTime) / CLOCKS_PER_SEC);
    std::cout << "Game is running at " << gameFPS.GetFPS() << " fps" << std::endl;

    // CIRCLE TEST

    // Change circle's color
    // circle -> setFillColor(sf::Color(0, 255, 0, int((double (elapsedTime) / CLOCKS_PER_SEC) * 25) % 256));
    // window -> draw(*circle);
    
    // std::cout << "Yo i was here" << std::endl;
     
    // END CIRCLE TEST
}

void Game::EndGame(){

}

void Game::createBird(){
    Birds* bird = new Birds();
    bird -> setWindow(window);
    bird -> setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    birds.push_back(bird);
}

void Game::removeBird(int id){
    if (birds.size() > id){
        delete birds[id];
        birds[id] = birds[birds.size() - 1];
        birds.pop_back();
    }
}

void Game::createBalloon(){
    Balloon* balloon = new Balloon();
    balloon -> setWindow(window);
    balloon -> setSize(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    balloons.push_back(balloon);
}

void Game::removeBalloon(int id){
    if (balloons.size() > id){
        delete balloons[id];
        balloons[id] = balloons[balloons.size() - 1];
        balloons.pop_back();
    }
}
