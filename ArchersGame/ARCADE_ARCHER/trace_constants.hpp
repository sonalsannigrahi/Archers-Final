#ifndef TRACE_CONSTANTS_HPP_INCLUDED
#define TRACE_CONSTANTS_HPP_INCLUDED

#include<bits/stdc++.h>

class TraceConstants{
private:
    double max_radius;
    double life_time_sec;
public:
    TraceConstants(double max_radius = 0.0, double life_time_sec = 0.0);

    double get_max_radius();
    double get_life_time_sec();

};

#endif // TRACE_CONSTANTS_HPP_INCLUDED
