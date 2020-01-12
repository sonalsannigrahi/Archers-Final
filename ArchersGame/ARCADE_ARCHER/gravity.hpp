#ifndef GRAVITY_HPP_INCLUDED
#define GRAVITY_HPP_INCLUDED

#include "VECTOR_2D.hpp"
#include "fire_ball.hpp"

#include<bits/stdc++.h>


class GravityGenerator{
private:

public:
    virtual void force_generate(FIRE_BALL& ball) = 0;
};


class UniformGravity:public GravityGenerator{
private:
    Vector2D g;
public:
    UniformGravity();
    UniformGravity(Vector2D& g);

    virtual void force_generate(FIRE_BALL& ball);
};

class BlackHole:public GravityGenerator{
private:
    Vector2D pos;
    double GAMA;
public:
    BlackHole(Vector2D& pos,double GAMA);
    virtual void force_generate(FIRE_BALL& ball);
};



class Gravity{
private:
    std::vector<GravityGenerator*> gravityGenerators;
public:
    void add_gravityGenerator(GravityGenerator& gravity_gen);
    void GenForce(FIRE_BALL& ball);
};



#endif // GRAVITY_HPP_INCLUDED
