#include"Setting.hpp"
#include "../Game/Game.hpp"

Setting::Setting(){
    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile("Setting/Asset/" + settingConstants.settingButtonImage);
    settingButton = new sf::Sprite(*texture);
    settingButton -> setScale(settingConstants.scale, settingConstants.scale);
}

void Setting::setWindow(sf::RenderWindow* window){
    this -> window = window;
}

void Setting::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;
    settingButton -> setPosition(windowWidth - settingButton -> getGlobalBounds().width, 0.0);
}

void Setting::setGame(Game* game){  
    this -> game = game;
}

void Setting::updateFrame(double time){
    window -> draw(*settingButton);
    /*
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    // transform the mouse position from window coordinates to world coordinates
    sf::Vector2i localPosition = sf::Mouse::getPosition(window);

    // retrieve the bounding box of the sprite
    sf::FloatRect bounds = settingButton.getGlobalBounds();

    // hit test
    if (settingButton.contains(localPosition))
    {
        sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
        window.draw(rectangle);
    }
}
        }
    //}
    // Ex
    //std::cout << game -> getFireworksRate() << std::endl;
    //game -> setFireworksRate(std::max((float) 1.0, (float) game -> getFireworksRate() - (float) time / 100));
    //game -> toggleBalloons();
}

*/
