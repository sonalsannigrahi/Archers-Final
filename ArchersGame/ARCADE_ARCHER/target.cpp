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

    if( dist < radius )
    {
        std::cout << "HIT!!!" << std::endl;
        std::cout << "HIT!!!" << std::endl;
        
        isAlive = false;
        for(;;);
    }

    std::pair< std::vector<FIRE_BALL*>, std::vector<BoxParticle*> > ans(fire_balls_vect, box_particles_vect);
    return ans;
}






