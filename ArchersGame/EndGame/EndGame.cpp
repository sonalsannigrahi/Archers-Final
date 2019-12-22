#include "EndGame.hpp"

EndGame::EndGame(){
    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile("EndGame/Assets/defeat.png");
    defeat -> setTexture(*texture);
    sf::Texture* background = new sf::Texture();
    background -> loadFromFile("EndGame/Assets/defback.png");
    defback -> setTexture(*background);
}

void EndGame::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void EndGame::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;

    defeat -> setScale(0.8f, 0.8f);
    defeat -> setPosition(windowWidth/4.7, windowHeight/8);
    defback -> setScale(windowWidth, windowHeight);
}

void EndGame::updateFrame(double time){
    //std::cout << "Yo i was here" << std::endl;
    window -> draw(*defback);
    window -> draw(*defeat);
}

