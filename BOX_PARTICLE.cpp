#include "BOX_PARTICLE.hpp"



BoxParticle::BoxParticle(sf::RenderWindow* cwindow, double length, double mass, Vector2D cPos, Vector2D cVel, double angle, double angle_vel):
    window(cwindow),
    Pos(cPos),
    Vel(cVel)
{
    this->length = length;
    this->mass = mass;

    this->angle = angle;
    this->angle_vel = angle_vel;
}


void BoxParticle::update(double duration)
{
    Vector2D G(0.0, -10.0);

    Vel += G * duration;
    Pos += Vel * duration;

    angle += angle_vel * duration;

}

bool BoxParticle::check_if_outside_of_border()
{
    Vector2D e_1(1.0,0);
    e_1.turn(angle);

    Vector2D e_2 = e_1;
    e_2.turn(pi/2);


    Vector2D p_1 = (length/2) * (e_1 + e_2);
    p_1 = p_1 + Pos;

    Vector2D p_2 = (length/2) * (e_2 - e_1);
    p_2 = p_2 + Pos;

    Vector2D p_3 = (-length/2) * (e_1 + e_2);
    p_3 = p_3 + Pos;

    Vector2D p_4 = (length/2) * (e_1 - e_2);
    p_4 = p_4 + Pos;


    double max_height = p_1.get_y();
    max_height = std::max(max_height, p_2.get_y());
    max_height = std::max(max_height, p_3.get_y());
    max_height = std::max(max_height, p_4.get_y());

    if(max_height < 0.0){
        return true;
    }
    else{
        return false;
    }
}














