#include "target_creator.hpp"

TargetCreator::TargetCreator(sf::RenderWindow* window, double length)
{
    double eps = 1e-6;

    this->W = window->getSize().x;
    this->H = window->getSize().y;

    bool good = true;
    if(abs((int)(W/(2*length)) - (W/(2*length))) > eps){
        good = false;
    }
    if(abs((int)(H/(2*length)) - (H/(2*length))) > eps){
        good = false;
    }


    this->window = window;
    this->length = length;
}

Target* TargetCreator::createTarget()
{
    srand(time(NULL));

    W = window->getSize().x;
    H = window->getSize().y;

    int W_N = (int)(W/(2*length));
    int H_N = (int)(H/(2*length));

    int W_POS = rand()%W_N;
    int H_POS = rand()%H_N;

    Target* nTarget = new Target(W/2 + (W_POS + 0.5) * length, H/2 + (H_POS + 0.5) * length, length, window);
    return nTarget;

}
