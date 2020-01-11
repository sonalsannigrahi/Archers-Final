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

void Targets::update(double duration, FIRE_BALLS& fireBalls, BoxParticles& boxParticles)
{
    ///std::cout << "target size          " <<  targets.size() << std::endl;
    for(int i=0;i<targets.size();i++){

        ///std::cout << targets[i]->Age << " ";

        targets[i]->update(duration);
    }
    ///std::cout << std::endl;
    ///std::cout << "target ---  size          " <<  targets.size() << std::endl;
    
    for(int i=0;i<targets.size();i++){
        if(targets[i]->alive()){
            std::vector<FIRE_BALL*> balls = fireBalls.getBALLS();
            
            ///std::cout <<  " " << balls.size() << std::endl;

            for(int j=0;j<balls.size();j++){
                
                
                
                std::pair< std::vector<FIRE_BALL*>, std::vector<BoxParticle*> > resolve = targets[i]->resolve(balls[j]);
                


                if(resolve.second.size() > 0){

                    ///std::cout << "HOOH" << std::endl;

                    for(int h=0;h<resolve.second.size();h++){
                        boxParticles.addBoxParticle(resolve.second[h]);
                    }
                    
                    for(int h=0;h<resolve.first.size();h++){
                        fireBalls.AddBall(resolve.first[h]);
                    }
                    fireBalls.RemBall(balls[j]);
                    balls[j] = balls[balls.size() - 1];
                    balls.pop_back();
                    
                }
            }
        }
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




void Targets::run(double duration, FIRE_BALLS& fireBalls, BoxParticles& boxParticles)
{
    ///std::cout << " before         " << nAlive() << std::endl;
    update(duration, fireBalls, boxParticles);
    ///std::cout << "gogogo" << std::endl;
    /**
    for(int i=0;i<targets.size();i++){
        std::cout << targets[i]->alive() << " ";
    }
    std::cout << std::endl;
    std::cout << " after         " << nAlive() << std::endl;
    
    **/

    for(int i=0;i<targets.size();i++){
        if(targets[i]->alive() == false){
            ///std::cout << "YLEEEEEEEEE" << std::endl;
            delete targets[i];

            targets[i] = targets[ targets.size() - 1 ];
            targets.pop_back();
        }
    }
    ///std::cout << " after  after       " << nAlive() << std::endl;
    if(nAlive() == 0){
        targets.push_back(targetCreator.createTarget());
    }

    show();
}







