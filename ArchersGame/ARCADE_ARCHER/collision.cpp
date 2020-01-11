#include "collision.hpp"



double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}


CollisionGenerator::CollisionGenerator(sf::RenderWindow* target)
{
    this->target = target;
    W = target->getSize().x;
    H = target->getSize().y;
}

void CollisionGenerator::ResCollsWithFrame(FIRE_BALL& ball)
{

    W = target->getSize().x;
    H = target->getSize().y;

    double eps = 1e-6;

    double RestitutionCoeff = 0.8;

    if(ball.Pos.get_y() + ball.RADIUS > H && ball.Vel.get_y() > 0)
    {
        ball.Vel.set_y(-ball.Vel.get_y());
    }
    if(ball.Pos.get_y() - ball.RADIUS < 0 && ball.Vel.get_y() < 0)
    {
        if(ball.Vel.get_y() > -eps)
        {
            ball.Vel.set_y(0.0);
            ball.Pos.set_y(0.0);
        }
        else{
            ball.Vel.set_y( - RestitutionCoeff * ball.Vel.get_y() );
        }
    }


    if(ball.Pos.get_x() + ball.RADIUS > W && ball.Vel.get_x() > 0)
    {
        ///std::cout<<"WHAT?"<<std::endl;
        ball.Vel.set_x( - RestitutionCoeff * ball.Vel.get_x());
    }
    if(ball.Pos.get_x() - ball.RADIUS < 0 && ball.Vel.get_x() < 0)
    {
        ///std::cout<<"WHAT?"<<std::endl;
        ball.Vel.set_x( - RestitutionCoeff * ball.Vel.get_x());
    }
}


std::vector<FIRE_BALL*> CollisionGenerator::ResCollsWithFrame_explode(FIRE_BALL& ball)
{
    W = target->getSize().x;
    H = target->getSize().y;

    std::vector<FIRE_BALL*> n_balls;

    double eps = 1e-6;

    double RestitutionCoeff = 0.8;

    if(ball.Pos.get_y() + ball.RADIUS > H && ball.Vel.get_y() > 0)
    {
        ball.Vel.set_y(-ball.Vel.get_y());
    }
    if(ball.Pos.get_y() - ball.RADIUS < 0 && ball.Vel.get_y() < 0)
    {
        if(ball.Vel.get_y() > -eps)
        {
            ball.Vel.set_y(0.0);
            ball.Pos.set_y(0.0);
        }
        else{
            ball.Vel.set_y( - RestitutionCoeff * ball.Vel.get_y() );
        }
    }


    if(ball.Pos.get_x() + ball.RADIUS > W && ball.Vel.get_x() > 0)
    {
        ///std::cout<<"WHAT?"<<std::endl;

        int N_cnt = 5;
        srand(time(NULL));

        for(int i=0;i<N_cnt;i++){
            /// RANDOM COLORS
            int R = rand()%255 + 1;
            int G = rand()%255 + 1;
            int B = rand()%255 + 1;

            double RADIUS = ball.getRadius();

            Vector2D pos = Vector2D( fRand(-RADIUS,RADIUS), fRand(-RADIUS,RADIUS) );
            pos += ball.getPos();

            /// IN RADIANS

            double theta_max = 10 * ( 2 * pi / 360 );

            double theta = fRand(-theta_max, theta_max);

            Vector2D vel = ball.getVel();
            vel.turn(theta);

            FIRE_BALL* n_ball = new FIRE_BALL(ball.getMass()/N_cnt, 10.0, pos, vel, sf::Color(R,G,B));
            n_balls.push_back(n_ball);
        }

    }
    if(ball.Pos.get_x() - ball.RADIUS < 0 && ball.Vel.get_x() < 0)
    {
        ///std::cout<<"WHAT?"<<std::endl;
        ball.Vel.set_x( - RestitutionCoeff * ball.Vel.get_x());
    }

    return n_balls;
}

bool CollisionGenerator::Collide(FIRE_BALL& ball_1, FIRE_BALL& ball_2)
{
    ///std::cout<<"HA!"<<std::endl;
    ///std::cout<<ball_1.Pos.get_x()<<" "<<ball_1.Pos.get_y()<<"; "<<ball_2.Pos.get_x()<<" "<<ball_2.Pos.get_y()<<std::endl;

    ///std::cout<<ball_2.Pos.get_x()<<" "<<ball_2.Pos.get_y()<<std::endl;

    Vector2D diff = ball_1.getPos() - ball_2.getPos();
    ///std::cout<<diff.get_x()<<" "<<diff.get_y()<<std::endl;
    ///std::cout<<diff.len()<<std::endl;


    if(ball_1.RADIUS + ball_2.RADIUS > (ball_1.getPos() - ball_2.getPos()).len()){
        Vector2D PosRel = ball_1.getPos() - ball_2.getPos();
        Vector2D VelRel = ball_1.getVel() - ball_2.getVel();
        ///std::cout<<"AH!"<<std::endl;
        if( PosRel * VelRel < 0 ){
            return true;
        }
    }
    return false;
}


void CollisionGenerator::ResCollision(FIRE_BALL& ball_1,FIRE_BALL& ball_2)
{
    if(!this->Collide(ball_1,ball_2))
        return;
    ///std::cout<<"MISSED!"<<std::endl;
    double eps = 1e-6;

    Vector2D e_n = ball_1.getPos() - ball_2.getPos();
    while(e_n.len() > 1 + eps )
        e_n.normalize();

    Vector2D e_t = e_n;
    e_t.turn(pi/2.0);
    while(e_t.len() > 1 + eps )
        e_t.normalize();

    Vector2D vel_1_initial = ball_1.getVel();
    Vector2D vel_2_initial = ball_2.getVel();

    double vel_1_initial_n = vel_1_initial*e_n;
    double vel_2_initial_n = vel_2_initial*e_n;
    double vel_1_initial_t = vel_1_initial*e_t;
    double vel_2_initial_t = vel_2_initial*e_t;

    double CM_vel =(ball_1.getMass()*vel_1_initial_n + ball_2.getMass()*vel_2_initial_n)/( ball_1.getMass() + ball_2.getMass() );

    double vel_1_final_n = 2 * CM_vel - vel_1_initial_n;
    double vel_2_final_n = 2 * CM_vel - vel_2_initial_n;

    Vector2D vel_1_final = vel_1_final_n * e_n + vel_1_initial_t * e_t;
    Vector2D vel_2_final = vel_2_final_n * e_n + vel_2_initial_t * e_t;

    ball_1.Vel = vel_1_final;
    ball_2.Vel = vel_2_final;
}





