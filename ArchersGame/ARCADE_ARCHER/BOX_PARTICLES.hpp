#ifndef BOX_PARTICLES_HPP_INCLUDED
#define BOX_PARTICLES_HPP_INCLUDED

#include "VECTOR_2D.hpp"
#include "BOX_PARTICLE.hpp"

#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>


class BoxParticles{
private:
    sf::RenderWindow* window;

    std::vector<BoxParticle*> particles;

public:

    BoxParticles(sf::RenderWindow* window);

    void addBoxParticle(BoxParticle* particle);

    void update(double duration);
    void show();
    void check_update();
};


#endif // BOX_PARTICLES_HPP_INCLUDED
