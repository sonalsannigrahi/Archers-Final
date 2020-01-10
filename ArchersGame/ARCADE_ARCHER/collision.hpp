#ifndef COLLISION_HPP_INCLUDED
#define COLLISION_HPP_INCLUDED

#include "VECTOR_2D.hpp"
#include "fire_ball.hpp"

#include<bits/stdc++.h>


class CollisionGenerator{
private:
    double W,H;
public:
    CollisionGenerator(sf::RenderTarget& target);

    void ResCollsWithFrame(FIRE_BALL& ball);

    std::vector<FIRE_BALL*> ResCollsWithFrame_explode(FIRE_BALL& ball);

    bool Collide(FIRE_BALL& ball_1,FIRE_BALL& ball_2);
    void ResCollision(FIRE_BALL& ball_1,FIRE_BALL& ball_2);

};


#endif // COLLISION_HPP_INCLUDED
