#include "StartScreen.hpp"

StartScreen::StartScreen(){
    srand(time(NULL)); // Randomize

    // Create game window
    sf::VideoMode videoMode = sf::VideoMode(gameConstants.WINDOW_WIDTH, gameConstants.WINDOW_HEIGHT);
    window = new sf::RenderWindow(videoMode, "Archers Game");
    run();
}

StartScreen::~StartScreen(){
}

void StartScreen::run(){


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

void StartScreen::UpdateFrame(){
    // std::cout << "Updating Frame at " << double(elapsedTime) / CLOCKS_PER_SEC << std::endl;


    // Calculate time has passed since the last UpdateFrame
    double time = double(clock() - elapsedTime) / CLOCKS_PER_SEC;
    elapsedTime = clock();

    // Draw Background
    window -> draw(startScreenConstants.filename);
}

void StartScreen::EndGame(){

}