#include "buttons.hpp"

#include<string>

StartButtons::Buttons(){
        sf::Texture* PlayButtonTexture = new sf::Texture();
        PlayButtonTexture -> loadFromFile("Buttons/asset/PlayButton.png");
        sf::Sprite* PlayButtonSprite = new sf::Sprite(*PlayButtonTexture);
        PlayButtonSprite.push_back(*PlayButtonSprite);

        sf::Texture* SettingButtonTexture = new sf::Texture();
        SettingButtonTexture -> loadFromFile("Buttons/asset/SettingButton.png");
        sf::Sprite* SettingButtonSprite = new sf::Sprite(*SettingButtonTexture);
        SettingButtonSprite.push_back(*PlayButtonSprite);


}

void Buttons::isButtonClicked(sf::Sprite sprite) {
    sf::IntRect rect(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

    if rect.contains(sf::Mouse::getPosition())
        return true;
    
    return false;
}

void Buttons::setWindow(sf::RenderWindow* gameWindow) {
    window = gameWindow;
} 

void Buttons::setSize(int width, int height) {
    windowWidth = width;
    windowHeight = height;
    PlayButtonSprite.setPosition((width / 2) - (PlayButtonSprite.getGlobalBounds().width / 2), (height / 2) - (PlayButtonSprite.getGlobalBounds().height / 2));

}



void Button::updateFrame(double time) {
    window -> draw(PlayButtonSprite);
    window -> draw(SettingButtonSprite);
}



void Buttons::HandleInput() {
    sf::Event event;

    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
            window.close();
            break;
        }
    } 
}


bool Buttons::loadgame() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)):
        if (isButtonClicked(PlayButtonSprite)) {
            return true
        else {
            return false
        }
    else {
        return false
    }
}
