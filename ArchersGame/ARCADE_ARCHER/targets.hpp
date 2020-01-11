#ifndef TARGETS_HPP_INCLUDED
#define TARGETS_HPP_INCLUDED

#include "target_creator.hpp"
#include "BOX_PARTICLES.hpp"
#include "fire_balls.hpp"


#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

class Targets{
private:
    double target_length;
    std::vector<Target*> targets;

    TargetCreator targetCreator;

    sf::RenderWindow* window;
public:
    Targets(sf::RenderWindow* window, double target_length);

    void update(double duration,FIRE_BALLS& fireBalls, BoxParticles& boxParticles);

    int nAlive();

    void show();

    void run(double duration);
};

#endif // TARGETS_HPP_INCLUDED
