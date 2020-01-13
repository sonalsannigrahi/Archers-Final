#include "gravity.hpp"

UniformGravity::UniformGravity()
{

    this->NAME = "UniformGravity";

    g = Vector2D(0.0, -10.0);
}

UniformGravity::UniformGravity(Vector2D& g)
{
    this->NAME = "UniformGravity";

    this->g = g;
}

std::string UniformGravity::getName()
{
    return this->NAME;
}

void UniformGravity::force_generate(FIRE_BALL& ball){
    Vector2D AddForce = ball.getMass() * g;
    ball.updateForceTot(AddForce);
}

void UniformGravity::show(sf::RenderWindow* window)
{
    //Do nothing function
    bool DO_NOTHING = true;
}


BlackHole::BlackHole(Vector2D& pos, double GAMA)
{
    this->NAME = "BlackHole";

    this->GAMA = GAMA;
    this->pos = pos;
}

std::string BlackHole::getName()
{
    return this->NAME;
}



void BlackHole::show(sf::RenderWindow* window)
{
    double outer_radius = 30.0;
    double inner_radius = 10.0;
    
    sf::CircleShape shape_outer(outer_radius);
    sf::CircleShape shape_inner(inner_radius);

    shape_outer.setFillColor(sf::Color(192,192,192));
    shape_inner.setFillColor(sf::Color::Black);

    double pos_x = pos.get_x();
    double pos_y = pos.get_y();

    shape_outer.setPosition(pos_x - outer_radius, window->getSize().y - (pos_y + outer_radius) );
    shape_inner.setPosition(pos_x - inner_radius, window->getSize().y - (pos_y + inner_radius) );
    
    window->draw(shape_outer);
    window->draw(shape_inner);

}

void BlackHole::force_generate(FIRE_BALL& ball)
{
    Vector2D PosRel = ball.getPos() - pos;

    Vector2D AddForce = ((-GAMA * ball.getMass())/pow(PosRel.len(),3.0)) * PosRel;
    ball.updateForceTot(AddForce);
}

void Gravity::show(sf::RenderWindow* window)
{
    for(int i=0;i<gravityGenerators.size();i++){
        if( gravityGenerators[i]->getName() == "BlackHole" ){
            gravityGenerators[i]->show(window);
        }
    }
}

void Gravity::add_gravityGenerator(GravityGenerator& gravityGen)
{
    gravityGenerators.push_back(&gravityGen);
}

void Gravity::GenForce(FIRE_BALL& ball)
{
    for(int i=0;i<gravityGenerators.size();i++)
    {
        gravityGenerators[i]->force_generate(ball);
    }
}





