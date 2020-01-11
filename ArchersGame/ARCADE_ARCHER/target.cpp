#include "target.hpp"


Target::Target(double pos_x, double pos_y, double length, sf::RenderWindow* window)
{
    ///std::cout << "CREATE NEW ONE" << std::endl;
    this->Age = 0.0;
    this->MaxAge = 100.0;

    isAlive = true;

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

    std::cout<< dist << " " << radius <<  std::endl;

    std::pair< std::vector<FIRE_BALL*>, std::vector<BoxParticle*> > ans(fire_balls_vect, box_particles_vect);
    

    if(ball->getRadius() > 15.0  && dist < radius )
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

                BoxParticle* box_particle = new BoxParticle(window, length/N_B, 20.0, Vector2D(X + cnt_x,Y + cnt_y), Vel, 0.0, angle_vel);
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

            FIRE_BALL* n_ball = new FIRE_BALL(ball->getMass()/N_cnt, 10.0, pos, vel, sf::Color(R,G,B));
            ans.first.push_back(n_ball);
        }



    }

    return ans;
}






