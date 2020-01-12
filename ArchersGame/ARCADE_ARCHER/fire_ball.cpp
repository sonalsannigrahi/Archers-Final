#include<bits/stdc++.h>

#include "VECTOR_2D.hpp"
#include "fire_ball.hpp"



FIRE_BALL::FIRE_BALL(string WHO_THROWED_IT, double MASS, double RADIUS, Vector2D Pos, Vector2D Vel,sf::Color color)
{
    this->WHO_THROWED_IT = WHO_THROWED_IT;

    this->MASS = MASS;
    this->RADIUS = RADIUS;

    this->color = color;

    this->Pos = Vector2D(Pos);
    this->Vel = Vector2D(Vel);

    this->ForceTot = Vector2D(0.0,0.0);
}

double FIRE_BALL::getMass() const
{
    return this->MASS;
}

double FIRE_BALL::getRadius() const
{
    return this->RADIUS;
}

Vector2D FIRE_BALL::getPos() const
{
    return this->Pos;
}

Vector2D FIRE_BALL::getVel() const
{
    return this->Vel;
}

void FIRE_BALL::ResetForce()
{
    this->ForceTot = Vector2D();
}


void FIRE_BALL::updateForceTot(Vector2D AddForce)
{
    this->ForceTot += AddForce;
}


void FIRE_BALL::update(double duration)
{
    Pos += Vel * duration;
    Vel += ForceTot/MASS * duration;
}


string FIRE_BALL::getWhoThrowedIt()
{
    return this->WHO_THROWED_IT;
}



