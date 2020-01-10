#include "fire_balls.hpp"

FIRE_BALLS::FIRE_BALLS(sf::RenderWindow* window):
    collisionGenerator(*window)
{
    this->window = window;

    UniformGravity* uniformGravity = new UniformGravity();
    gravity.add_gravityGenerator(*uniformGravity);
}

void FIRE_BALLS::AddBall(FIRE_BALL* ball)
{
    BALLS.push_back(ball);
}
void FIRE_BALLS::draw()
{
    for(int i=0;i<BALLS.size();i++)
    {
        window->draw(*BALLS[i]);
    }
}

void FIRE_BALLS::show()
{
    this->draw();
}

void FIRE_BALLS::update(double duration)
{
    int LEN = BALLS.size();
    for(int i=0;i<LEN;i++)
    {
        BALLS[i]->ResetForce();
    }

    for(int i=0;i<LEN;i++)
    {
        gravity.GenForce(*BALLS[i]);
        if(BALLS[i]->getRadius() < 15.0)
            collisionGenerator.ResCollsWithFrame(*BALLS[i]);
        else{

            std::vector<FIRE_BALL*> n_balls = collisionGenerator.ResCollsWithFrame_explode(*BALLS[i]);
            if( n_balls.size() > 0 )
            {
                delete BALLS[i];
                BALLS[i] = BALLS[ BALLS.size() - 1 ];
                BALLS.pop_back();
            }

            for(int j = 0;j<n_balls.size();j++){
                BALLS.push_back( n_balls[j] );
            }
        }
    }

    for(int i=0;i<LEN-1;i++)
    {
        for(int j=i+1;j<LEN;j++)
        {
            collisionGenerator.ResCollision(*BALLS[i],*BALLS[j]);
        }
    }

    for(int i=0;i<LEN;i++)
    {
        BALLS[i]->update(duration);
    }

}

std::vector<Trace*> FIRE_BALLS::genTrace(TraceConstants& traceConstants)
{
    std::vector<Trace*> traces;
    for(int i=0;i<BALLS.size();i++)
    {
        Trace* trace = new Trace(traceConstants, BALLS[i]->getPos());
        traces.push_back(trace);
    }
    return traces;
}







