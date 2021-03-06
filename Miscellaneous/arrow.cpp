#include "arrow.hpp"


Arrow::Arrow(): Rectangle(0,0,0,0,0,0,10,20, distr){}

Arrow::Arrow(double X_CM, double Y_CM, double V_X_CM, double V_Y_CM, double angle, double ang_acc, double a, double b, double m, std::string filename): Rectangle(X_CM, Y_CM, V_X_CM, V_Y_CM, angle, ang_acc, a,  b, distr){
    if (!this->texture.loadFromFile(filename)){
        std::cout << "Load failed" << std::endl;
    }
    this->MASS = m;
}

void Arrow::changeAngle(double alpha){
    this->angle = alpha;
}
void Arrow::shoot(double vel){//intial velocity is in m/s
    this->shot = true;
    this->vel_CM.y = sin(this->angle)*vel;
    this->vel_CM.x = cos(this->angle)*vel;
}

void Arrow::update(double time){
    //need to implement the movement using the physics engine point mass class, Arrow to be made a subclass?
    if (this->shot == true){
        rec_grav.force_torque_gen(*this);
        this->integrate(time); //as the arrow moves in a projectile, its object attributes (position velocity etc) are modified
        //via this function
    }
    //If the arrow isn't being shot, the Character object will call its change angle function, so when it
    //is updated, it just gets drawn as a drawable
    
}

double Arrow::inflictDamage(){
    return damage;
}

void Arrow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::ConvexShape shape;
    shape.setTexture(&this->texture);
    shape.setFillColor(sf::Color::Transparent);
    shape.setPointCount(4);

    Vector2D e_1(1.0,0);
    e_1.turn(angle);
    Vector2D e_2 = e_1;
    e_2.turn(pi/2);

    Vector2D p_1 = ( a/2.0 * e_1 - b/2.0 * e_2);
    p_1 = p_1 + pos_CM;
    Vector2D p_2 = ( a/2.0 * e_1 + b/2.0 * e_2);
    p_2 = p_2 + pos_CM;
    Vector2D p_3 = (-a/2.0 * e_1 + b/2.0 * e_2);
    p_3 = p_3 + pos_CM;
    Vector2D p_4 = (-a/2.0 * e_1 - b/2.0 * e_2);
    p_4 = p_4 + pos_CM;

    shape.setPoint(0,sf::Vector2f(p_1.x,target.getSize().y-p_1.y));
    shape.setPoint(1,sf::Vector2f(p_2.x,target.getSize().y-p_2.y));
    shape.setPoint(2,sf::Vector2f(p_3.x,target.getSize().y-p_3.y));
    shape.setPoint(3,sf::Vector2f(p_4.x,target.getSize().y-p_4.y));

    target.draw(shape);
}
