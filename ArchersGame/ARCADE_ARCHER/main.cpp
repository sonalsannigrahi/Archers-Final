#include "RETRO_GAME.hpp"
#include "RETRO_GAME_SETTINGS.hpp"

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


int main()
{
    ///srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(800, 600), "TEST!",sf::Style::Default);

    RetroGame game = RetroGame(&window);
    RetroGameSettings settings = RetroGameSettings(&window);


    STATES::STATES_ENUM state = STATES::SETTINGS;

    while(true)
    {
        ///CAN BE SIMPLIFIED USING SWITCH
        if(state == STATES::DEAD)
        {
            window.close();
            break;
        }
        else if(state == STATES::SETTINGS){
            state = settings.run();
        }
        else if(state == STATES::GAME){
            state = game.run();
        }
    }

    return 0;
}



