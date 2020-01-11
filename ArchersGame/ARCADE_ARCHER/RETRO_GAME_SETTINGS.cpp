#include "RETRO_GAME_SETTINGS.hpp"

RetroGameSettings::RetroGameSettings(sf::RenderWindow* window){
    this->window = window;
}

STATES::STATES_ENUM RetroGameSettings::run()
{
    while(window->isOpen())
    {
        sf::Event event;
        while(window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
                return STATES::DEAD;
            }
            else if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::S){
                    return STATES::GAME_RETRO;
                }
            }
        }
        window->clear();
        window->display();
    }
}
