#ifndef RETRO_GAME_HPP_INCLUDED
#define RETRO_GAME_HPP_INCLUDED

#include "fire_balls.hpp"
#include "player_box.hpp"
#include "targets.hpp"
#include "BOX_PARTICLES.hpp"
#include "HEALTH_BAR.hpp"

#include "STATES.hpp"

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class RetroGame{
private:

    sf::RenderWindow* window;

    FIRE_BALLS fireBalls;
    Targets targets;
    PLayerBox playerBox;

    BoxParticles boxParticles;

    clock_t time;

    double time_for_trace_cnst;
    double time_for_trace;

    std::vector<Trace*> traces;

public:
    RetroGame(sf::RenderWindow* window);
    STATES::STATES_ENUM run();
};


#endif // RETRO_GAME_HPP_INCLUDED
