#include "trace_constants.hpp"

TraceConstants::TraceConstants(double max_radius, double life_time_sec)
{
    this->max_radius = max_radius;
    this->life_time_sec = life_time_sec;
}

double TraceConstants::get_max_radius(){
    return max_radius;
}

double TraceConstants::get_life_time_sec(){
    return life_time_sec;
}
