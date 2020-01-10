#ifndef TARGET_CREATOR_HPP_INCLUDED
#define TARGET_CREATOR_HPP_INCLUDED

#include "target.hpp"

#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

class TargetCreator{
private:
    double W,H;

    double length;
    sf::RenderWindow* window;
public:
    TargetCreator(sf::RenderWindow* window, double length);
    Target* createTarget();
};


#endif // TARGET_CREATOR_HPP_INCLUDED
