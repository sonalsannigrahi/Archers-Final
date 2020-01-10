#ifndef TARGETS_HPP_INCLUDED
#define TARGETS_HPP_INCLUDED

#include "target_creator.hpp"

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

    void update(double duration);

    int nAlive();

    void show();

    void run(double duration);
};

#endif // TARGETS_HPP_INCLUDED
