#include "target.hpp"


double SIMULATE(Vector2D Pos, Vector2D Vel)
{
    FIRE_BALL* simulBall = new FIRE_BALL("Opponent", 2.0,30.0,Pos,Vel,sf::Color(255,255,255));

    UniformGravity* gravity = new UniformGravity();

    double DT = 0.005;
    while(simulBall->getPos().get_y() > 0)
    {
        simulBall->ResetForce();

        gravity->force_generate(*simulBall);

        simulBall->update(DT);
    }

    return simulBall->getPos().get_x();
}


Target::Target(int Level, double pos_x, double pos_y, double length, sf::RenderWindow* window)
{
    ///std::cout << "CREATE NEW ONE" << std::endl;
    this->Level = Level;

    this->Age = 0.0;
    this->MaxAge = 10.0;

    isAlive = true;


    counter_for_hurling = 0.0;
    interval_for_hurling = 3.0;

    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->length = length;

    this->window = window;
}

void Target::update(double duration)
{
    ///std::cout<<"HOoooooooooo"<<std::endl;

    ///std::cout << duration << std::endl;
    ///std::cout << Age << " " << MaxAge << std::endl;

    this->Age += duration;
    if(Age > MaxAge)
    {
        ///std::cout <<  " owoiwueio uie " << Age << " " << duration << std::endl;

        isAlive = false;
    }

    this->counter_for_hurling += duration;
}

bool Target::alive()
{
    return isAlive;
}

std::pair< std::vector<FIRE_BALL*>, std::vector<BoxParticle*> > Target::resolve(FIRE_BALL* ball)
{
    ///std::cout << "resolving " << std::endl;
    std::vector<FIRE_BALL*> fire_balls_vect;
    std::vector<BoxParticle*> box_particles_vect;

    std::vector< std::pair<Vector2D, Vector2D> > lines;

    Vector2D point_1(pos_x + length/2, pos_y + length/2);
    Vector2D point_2(pos_x - length/2, pos_y + length/2);
    Vector2D point_3(pos_x - length/2, pos_y - length/2);
    Vector2D point_4(pos_x + length/2, pos_y - length/2);

    Vector2D e_x(1.0,0.0);
    Vector2D e_y(0.0,1.0);

    lines.push_back(std::make_pair(point_1,point_2));
    lines.push_back(std::make_pair(point_2,point_3));
    lines.push_back(std::make_pair(point_3,point_4));
    lines.push_back(std::make_pair(point_4,point_1));

    double dist = INFINITY;
    Vector2D center(ball->getPos());
    double radius = ball->getRadius();

    for(int i=0;i<lines.size();i++){
        Vector2D point_a = lines[i].first;
        Vector2D point_b = lines[i].second;

        double distance;

        if( (center - point_a) * (point_b - point_a) < 0 ){
            distance = (center - point_a).len();
        }
        if( (center - point_b) * (point_a - point_b) < 0 ){
            distance = (center - point_b).len();
        }
        else{
            distance = ( (center - point_a) - ( ((center - point_a) * (point_b - point_a)) / (point_b - point_a).len() ) * (point_b - point_a) ).len();
        }
        dist = std::min(dist, distance);
    }

    ///std::cout<< dist << " " << radius <<  std::endl;

    std::pair< std::vector<FIRE_BALL*>, std::vector<BoxParticle*> > ans(fire_balls_vect, box_particles_vect);


    if(ball->getWhoThrowedIt() == "PLAYER" && ball->getRadius() > 15.0  && dist < radius )
    {
        std::cout << "HIT!!!" << std::endl;
        std::cout << "HIT!!!" << std::endl;

        isAlive = false;
        ///for(;;);


        double X = pos_x - length/2;
        double Y = pos_y - length/2;

        int N_B = 5;

        srand(time(NULL));

        for(int i=0;i<N_B;i++)
        {
            for(int j=0;j<N_B;j++)
            {
                double cnt_x = (length/N_B)*(i+0.5);
                double cnt_y = (length/N_B)*(j+0.5);


                double angle_vel = fRand(-0.5, 0.5);

                Vector2D Vel = ball->getVel();

                double scaling_factor = fRand(5.0, 10);
                Vel = Vel * scaling_factor;

                double theta = fRand(-pi/4, pi/4);

                Vel.turn(theta);

                BoxParticle* box_particle = new BoxParticle(window, length/N_B, 100.0, Vector2D(X + cnt_x,Y + cnt_y), Vel, 0.0, angle_vel);
                ans.second.push_back(box_particle);
            }
        }

        int N_cnt = 5;

        for(int i=0;i<N_cnt;i++){
            /// RANDOM COLORS
            int R = rand()%255 + 1;
            int G = rand()%255 + 1;
            int B = rand()%255 + 1;

            double RADIUS = ball->getRadius();

            Vector2D pos = Vector2D( fRand(-RADIUS,RADIUS), fRand(-RADIUS,RADIUS) );
            pos += ball->getPos();

            /// IN RADIANS

            double theta_max = 10 * ( 2 * pi / 360 );

            double theta = fRand(-theta_max, theta_max);

            Vector2D vel = ball->getVel();
            vel.turn(theta);

            FIRE_BALL* n_ball = new FIRE_BALL("PLAYER" ,ball->getMass()/N_cnt, 10.0, pos, vel, sf::Color(R,G,B));
            ans.first.push_back(n_ball);
        }



    }

    return ans;
}

FIRE_BALL* Target::hurl(PLayerBox& playerBox)
{
    if( counter_for_hurling > interval_for_hurling )
    {
        counter_for_hurling -= interval_for_hurling;


        Vector2D Pos(pos_x, pos_y);

        srand(time(NULL));

        double max_magnitude = 100.0;
        double magnitude = fRand(max_magnitude/2.0, max_magnitude);

        double theta_min = pi/6;
        double theta_max = pi/2;

        /// double theta = fRand(theta_min,theta_max);


        ///TERNARY search for optimal theta, assuming UNImodality

        double l_theta = theta_min;
        double r_theta = theta_max;

        double EPS = 0.1;

        while( r_theta - l_theta > EPS )
        {
            double m_first_theta = l_theta + (r_theta - l_theta) * (1.0/3);
            double m_second_theta = l_theta + (r_theta - l_theta) * (2.0/3);

            Vector2D Vel_L(0.0, magnitude);
            Vel_L.turn(l_theta);

            Vector2D Vel_M_first(0.0, magnitude);
            Vel_M_first.turn(m_first_theta);

            Vector2D Vel_M_second(0.0, magnitude);
            Vel_M_second.turn(m_second_theta);

            Vector2D Vel_R(0.0, magnitude);
            Vel_R.turn(r_theta);

            double pos_L = SIMULATE(Pos,Vel_L);
            double pos_M_first = SIMULATE(Pos,Vel_M_first);
            double pos_M_second = SIMULATE(Pos,Vel_M_second);
            double pos_R = SIMULATE(Pos,Vel_R);

            double X_TARGET = playerBox.pos_x;

            double dist_L = std::abs( X_TARGET - pos_L );
            double dist_M_first = std::abs( X_TARGET - pos_M_first );
            double dist_M_second = std::abs( X_TARGET - pos_M_second );
            double dist_R = std::abs( X_TARGET - pos_R );

            if(dist_M_first < dist_M_second){
                r_theta = m_second_theta;
            }
            else if(dist_M_first > dist_M_second){
                l_theta = m_first_theta;
            }
            else{
                l_theta = m_first_theta;
                r_theta = m_second_theta;
            }


        }

        double theta = fRand(l_theta, r_theta);

        Vector2D Vel(0.0, magnitude);
        Vel.turn(theta);

        FIRE_BALL* nBall = new FIRE_BALL("Opponent", 2.0,30.0,Pos,Vel,sf::Color(255,255,255));
        return nBall;
    }
    else{
        return nullptr;
    }
}




