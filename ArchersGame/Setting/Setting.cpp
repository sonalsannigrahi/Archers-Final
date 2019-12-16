#include"Setting.hpp"

Setting::Setting(){
    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile("Setting/Asset/" + settingConstants.settingButtonImage);
    SettingButton.setTexture(*texture);
}

void Setting::setWindow(sf::RenderWindow* window){
    window = window;
}

void Setting::setSize(int width, int height){
    windowWidth = width;
    windowHeight = height;
    SettingButton.setPosition(windowWidth - SettingButton.getGlobalBounds().width, 0);
}

void Setting::setGame(Game* game){
    game = game;
}

void Setting::updateFrame(double time){
    window -> draw(SettingButton);

    // Ex
    // game -> setBalloonsRate(3);
    // game -> toggleBalloons();
}

