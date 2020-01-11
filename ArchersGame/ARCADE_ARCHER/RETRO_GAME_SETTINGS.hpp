#ifndef RETRO_GAME_SETTINGS_HPP_INCLUDED
#define RETRO_GAME_SETTINGS_HPP_INCLUDED



#include "fire_balls.hpp"
#include "player_box.hpp"
#include "targets.hpp"

#include "STATES.hpp"

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class RetroGameSettings{
private:
    sf::RenderWindow* window;
public:
    RetroGameSettings(sf::RenderWindow* window);
    STATES::STATES_ENUM run();
};

#endif // RETRO_GAME_SETTINGS_HPP_INCLUDED
