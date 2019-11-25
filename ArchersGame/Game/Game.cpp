#include "Game.hpp"

Game::Game(){
    // Create game window
    sf::VideoMode videoMode = sf::VideoMode(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    window = new sf::RenderWindow(videoMode, "Archers");

    // Send window to Background
    gameBackground.window = window;

    // Start game
    std::cout << "Starting Game ..." << std::endl;
    StartGame();
}

Game::~Game(){
    delete circle;
    delete window;
}

void Game::StartGame(){
    // Draw a circle
    circle = new sf::CircleShape(100.f);
    circle -> setFillColor(sf::Color::Green);

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

    // Calculate time has passed since the last UpdateFrame
    double time = double(clock() - elapsedTime) / CLOCKS_PER_SEC;
    elapsedTime = clock();
    
    // Draw Background
    gameBackground.updateFrame(time);
    //std::cout << "Yo i was here" << std::endl;

    // Update FPS counter
    gameFPS.UpdateFPS(double(elapsedTime) / CLOCKS_PER_SEC);
    //std::cout << "Game is running at " << gameFPS.GetFPS() << " fps" << std::endl;

    // Change circle's color
    circle -> setFillColor(sf::Color(0, 255, 0, int((double (elapsedTime) / CLOCKS_PER_SEC) * 25) % 256));
    window -> draw(*circle);
    
    // std::cout << "Yo i was here" << std::endl;
}

void Game::EndGame(){

}
