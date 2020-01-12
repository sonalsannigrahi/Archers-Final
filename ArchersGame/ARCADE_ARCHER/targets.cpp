#include "targets.hpp"

Targets::Targets(sf::RenderWindow* window, double target_length):
    targetCreator(window, target_length)
{
    double eps = 1e-6;

    double W = window->getSize().x;
    double H = window->getSize().y;

    bool good = true;
    if(abs((int)(W/(2*target_length)) - (W/(2*target_length))) > eps){
        good = false;
    }
    if(abs((int)(H/(2*target_length)) - (H/(2*target_length))) > eps){
        good = false;
    }


    this->window = window;
    this->target_length = target_length;
}

void Targets::update(double duration)
{
    for(int i=0;i<targets.size();i++){
        targets[i]->update(duration);
    }
}

int Targets::nAlive()
{
    int n_alive = 0;
    for(int i=0;i<targets.size();i++){
        if(targets[i]->alive())
            n_alive++;
    }
    return n_alive;
}

void Targets::show()
{
    for(int i=0;i<targets.size();i++){
        window->draw(*targets[i]);
    }
}




void Targets::run(double duration)
{
    update(duration);

    for(int i=0;i<targets.size();i++){
        if(targets[i]->alive() == false){
            delete targets[i];

            targets[i] = targets[ targets.size() - 1 ];
            targets.pop_back();
        }
    }

    if(nAlive() == 0){
        targets.push_back(targetCreator.createTarget());
    }

    show();
}







