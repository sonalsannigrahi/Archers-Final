#include "gravity.hpp"

UniformGravity::UniformGravity()
{
    g = Vector2D(0.0, -10.0);
}

UniformGravity::UniformGravity(Vector2D& g)
{
    this->g = g;
}

void UniformGravity::force_generate(FIRE_BALL& ball){
    Vector2D AddForce = ball.getMass() * g;
    ball.updateForceTot(AddForce);
}




BlackHole::BlackHole(Vector2D& pos, double GAMA)
{
    this->GAMA = GAMA;
    this->pos = pos;
}

void BlackHole::force_generate(FIRE_BALL& ball)
{
    Vector2D PosRel = ball.getPos() - pos;

    Vector2D AddForce = ((-GAMA * ball.getMass())/pow(PosRel.len(),3.0)) * PosRel;
    ball.updateForceTot(AddForce);
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





