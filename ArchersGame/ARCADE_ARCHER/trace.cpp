#include "trace.hpp"

Trace::Trace(TraceConstants& constants, Vector2D pos)
{
    this->constants = constants;
    this->isAlive = true;

    this->Age = 0.0;
    this->radius = 0.0;

    this->pos = pos;
}

void Trace::update(double duration)
{
    Age += duration;
    if(Age >= constants.get_life_time_sec()){
        radius = 0.0;
        isAlive = false;
    }
    else{
        if(Age <= 0.5 * constants.get_life_time_sec()){
            radius = Age * constants.get_max_radius() / ( 0.5 * constants.get_life_time_sec() );
        }
        else{
            radius = ( constants.get_life_time_sec() - Age ) * constants.get_max_radius() / ( 0.5 * constants.get_life_time_sec() );
        }
    }
}

bool Trace::alive()
{
    return this->isAlive;
}
