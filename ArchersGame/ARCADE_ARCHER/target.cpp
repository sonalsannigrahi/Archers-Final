#include "target.hpp"

Target::Target(double pos_x, double pos_y, double length, sf::RenderWindow* window)
{
    this->Age = 0.0;
    this->MaxAge = 4.0;

    bool isAlive = true;

    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->length = length;

    this->window = window;
}

void Target::update(double duration)
{
    this->Age += duration;
}

bool Target::alive()
{
    if(Age >= MaxAge){
        return false;
    }
    return true;
}

std::pair< std::vector<FIRE_BALL*>, std::vector<BoxParticle*> > Target::resolve(FIRE_BALL* ball)
{
    std::vector<FIRE_BALL*> fire_balls_vect;
    std::vector<BoxParticle*> box_particles_vect;

    std::vector< std::pair<Vector2D, Vector2D> > lines;

    Vector2D point_1(pos_x + length/2, pos_y + length/2);
    Vector2D point_2(pos_x - length/2, pos_y + length/2);
    Vector2D point_3(pos_x - length/2, pos_y - length/2);
    Vector2D point_4(pos_x + length/2, pos_y - length/2);

    Vector2D e_x(1.0,0.0);
    Vector2D e_y(0.0,1.0);

    lines.push_back(std::make_pair(point_1,e_x));
    lines.push_back(std::make_pair(point_1,e_y));
    lines.push_back(std::make_pair(point_3,e_x));
    lines.push_back(std::make_pair(point_3,e_y));

    double dist = -1;
    Vector2D center(ball->getPos());
    double radius = ball->getRadius();

    for(int i=0;i<lines.size();i++){
        Vector2D point = lines[i].first;
        Vector2D direction = lines[i].second;

        Vector2D R = center - point;

        double distance = (R - (R * direction) * direction).len();
        if(dist == -1){
            dist = distance;
        }
        else{
            dist = std::min(distance, dist);
        }

    }

    if( dist < radius )
    {
        std::cout << "HIT!!!" << std::endl;
    }

    std::pair< std::vector<FIRE_BALL*>, std::vector<BoxParticle*> > ans(fire_balls_vect, box_particles_vect);
}






