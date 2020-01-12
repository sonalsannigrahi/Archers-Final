#include "EndGame.hpp"

EndGame::EndGame(){
    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile("EndGame/Assets/score.png");
    defeat -> setTexture(*texture);
    sf::Texture* background = new sf::Texture();
    background -> loadFromFile("EndGame/Assets/defback.png");
    defback -> setTexture(*background);
    sf::Texture* retry = new sf::Texture();
    retry -> loadFromFile("EndGame/Assets/replay.png");
    replay -> setTexture(*retry);
    sf::Texture* quit = new sf::Texture();
    quit -> loadFromFile("EndGame/Assets/exit.png");
    exit -> setTexture(*quit);
    sf::Texture* over = new sf::Texture();
    over -> loadFromFile("EndGame/Assets/gameover.png");
    gameover -> setTexture(*over);
}

void EndGame::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void EndGame::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;

    defback -> setScale(windowWidth, windowHeight);
    exit -> setPosition(sf::Vector2f((float)(windowWidth - 900) + windowWidth/3, (float) (windowHeight - 600) + windowHeight/2));
}

void EndGame::updateFrame(double time){
    //std::cout << "Yo i was here" << std::endl;
    sf::Vector2u windowSize;
    windowSize = window -> getSize();

    gameover -> setPosition(windowSize.x/2 - gameover -> getGlobalBounds().width/2, windowSize.y/4);
    gameover -> setScale(0.6f * windowSize.x / 900, 0.6f * windowSize.y / 600);
    defeat -> setScale(0.6f * windowSize.x / 900, 0.6f * windowSize.y / 600);
    defeat -> setPosition(windowSize.x/4, windowSize.y/2 + defeat -> getGlobalBounds().height);
    replay -> setPosition(windowSize.x/2 - windowSize.x/4, 3*float(windowSize.y)/4);
    replay -> setScale(0.6f * windowSize.x / 900, 0.6f * windowSize.y / 600);
    exit -> setPosition(windowSize.x/2 + windowSize.x/8, 3*float(windowSize.y)/4);
    exit -> setScale(0.6f * windowSize.x / 900, 0.6f * windowSize.y / 600);
    window -> draw(*defback);
    window -> draw(*replay);
    window -> draw(*exit);
    window -> draw(*gameover);
    window -> draw(*defeat);
}

