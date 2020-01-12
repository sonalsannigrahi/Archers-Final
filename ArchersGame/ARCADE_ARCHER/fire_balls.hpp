#ifndef FIRE_BALLS_HPP_INCLUDED
#define FIRE_BALLS_HPP_INCLUDED


#include "fire_ball.hpp"
#include "gravity.hpp"
#include "collision.hpp"
#include "trace.hpp"

///WILL BE CHANGED AFTER
#include<bits/stdc++.h>



class FIRE_BALLS{
private:
    std::vector<FIRE_BALL*> BALLS;

    Gravity gravity;
    CollisionGenerator collisionGenerator;

    sf::RenderWindow* window;

public:
    FIRE_BALLS(sf::RenderWindow* window);
    void AddBall(FIRE_BALL* ball);
    void RemBall(FIRE_BALL* ball);
    void draw();
    void show();

    void update(double duration);

    std::vector<FIRE_BALL*> getBALLS();

    std::vector<Trace*> genTrace(TraceConstants& traceConstants);

};

#endif // FIRE_BALLS_HPP_INCLUDED
