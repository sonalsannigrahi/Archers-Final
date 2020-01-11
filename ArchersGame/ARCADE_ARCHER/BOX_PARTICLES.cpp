#include "BOX_PARTICLES.hpp"

BoxParticles::BoxParticles(sf::RenderWindow* window)
{
    this->window = window;
}

void BoxParticles::addBoxParticle(BoxParticle* particle)
{
    particles.push_back(particle);
}

void BoxParticles::check_update()
{
    for(int i=0;i<particles.size();i++){
        if(particles[i]->check_if_outside_of_border()){
            delete particles[i];
            particles[i] = particles[ particles.size() - 1 ];
            particles.pop_back();
        }
    }
}

void BoxParticles::update(double duration)
{
    for(int i=0;i<particles.size();i++){
        particles[i]->update(duration);
    }
}

void BoxParticles::show()
{
    for(int i=0;i<particles.size();i++){
        window->draw(*particles[i]);
    }
}
