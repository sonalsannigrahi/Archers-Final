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


        sf::Font font;
        font.loadFromFile("ARCADE_ARCHER/font.TTF");

        sf::Text text;
        text.setFont(font);

        text.setString(" TO START THE GAME PRESS S \n ( TO RETURN TO THIS PAGE,\n ALSO PRESS S )");
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Red);
        text.setPosition(0.0, window->getSize().y/6 );
        window->draw(text);


        window->display();
    }
}
