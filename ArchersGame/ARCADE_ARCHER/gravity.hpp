#ifndef GRAVITY_HPP_INCLUDED
#define GRAVITY_HPP_INCLUDED

#include "VECTOR_2D.hpp"
#include "fire_ball.hpp"

#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

class GravityGenerator{
private:

public:
    virtual void force_generate(FIRE_BALL& ball) = 0;
    virtual std::string getName() = 0;
    virtual void show(sf::RenderWindow* window) = 0;
};


class UniformGravity:public GravityGenerator{
private:
    Vector2D g;

    std::string NAME;

public:
    UniformGravity();
    UniformGravity(Vector2D& g);

    virtual std::string getName();
    virtual void show(sf::RenderWindow* window);
    virtual void force_generate(FIRE_BALL& ball);
};

class BlackHole:public GravityGenerator{
private:
    Vector2D pos;
    double GAMA;

    std::string NAME;

public:
    virtual std::string getName();

    virtual void show(sf::RenderWindow* window);

    BlackHole(Vector2D& pos,double GAMA);
    virtual void force_generate(FIRE_BALL& ball);
};



class Gravity{
private:
    std::vector<GravityGenerator*> gravityGenerators;
public:

    void show(sf::RenderWindow* window);

    void add_gravityGenerator(GravityGenerator& gravity_gen);
    void GenForce(FIRE_BALL& ball);
};



#endif // GRAVITY_HPP_INCLUDED
