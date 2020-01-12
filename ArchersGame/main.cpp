#include "Game/Game.hpp"

#include "ARCADE_ARCHER/RETRO_GAME.hpp"
#include "ARCADE_ARCHER/RETRO_GAME_SETTINGS.hpp"



int main()
{
    Game* game = new Game();
    
    sf::RenderWindow* window = game->getWindow();

    RetroGame retroGame = RetroGame(window);
    
    RetroGameSettings retroGameSettings = RetroGameSettings(window);

    STATES::STATES_ENUM state = STATES::SETTINGS;

    while(true)
    {
        if( state == STATES::DEAD )
        {
            window->close();
            break;
        }
        else if(state == STATES::GAME_CLASSIC)
        {
            state = game->StartGame();
        }
        else if(state == STATES::GAME_RETRO)
        {
            retroGame = RetroGame(window);

            state = retroGame.run();
        }
        else if(state == STATES::SETTINGS)
        {
            state = retroGameSettings.run();
        }
    }

    game->StartGame();


    return 0;
}
