#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>

#include <cmath>
#include <vector>
#include <algorithm>
#include "physics.hpp"

using namespace std;

Vector2D::Vector2D(double x, double y){
    this->x = x;
    this->y = y;
}
Vector2D::Vector2D(){
    this->x = 0.0;
    this->y = 0.0;
}
double Vector2D::get_x(){return this->x;}
double Vector2D::get_y(){return this-> y;}
double Vector2D::len(){
    double ans = sqrt(x*x + y*y);
    return ans;
}
void Vector2D::normalize(){
    if( this->len() !=0 ){
        x = x / this->len();
        y = y / this->len();
    }
}
void Vector2D::turn(double angle){
    /// angles in radians
    double n_x = cos(angle) * x - sin(angle) * y;
    double n_y = sin(angle) * x + cos(angle) * y;
    x = n_x;
    y = n_y;
}
Vector2D Vector2D::operator/(double k){
    Vector2D ans;
    ans.x = x/k;
    ans.y = y/k;
    return ans;
}
Vector2D Vector2D::operator+(Vector2D other){
    Vector2D ans;
    ans.x = this->x + other.x;
    ans.y = this->y + other.y;
    return ans;
}
Vector2D Vector2D::operator-(Vector2D other){
    Vector2D ans;
    ans.x = this->x - other.x;
    ans.y = this->y - other.y;
    return ans;
}
Vector2D Vector2D::operator*(double k){
    Vector2D ans;
    ans.x = (this->x)*k;
    ans.y = (this->y)*k;
    return ans;
}
Vector2D& Vector2D::operator+=(const Vector2D& other){
    this->x += other.x;
    this->y += other.y;
    return *this;
}
double Vector2D::operator*(Vector2D other){
    double ans = (this->x)*(other.x) + (this->y)*(other.y);
    return ans;
}
double Vector2D::operator^(Vector2D other){
    return this->x * other.y - this->y * other.x;
}

Vector2D operator*(double k, Vector2D v){
    return v*k;
}

void Point::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    sf::CircleShape shape(radius);
    shape.setPosition(x-radius,target.getSize().y - y - radius );
    target.draw(shape);
}
Point::Point(double _mass, double _x, double _y, double _v_x, double _v_y, double _radius){
    mass = _mass;

    x = _x;
    y = _y;

    v_x = _v_x;
    v_y = _v_y;

    f_x = 0.0;
    f_y = 0.0;

    radius = _radius;
}
double Point::energy(){
    double g = 10.0;
    double ans = (mass/2.0) * ( v_x * v_x + v_y * v_y ) + mass * g * y;
    return ans;
}
void Point::integrate(double duration){
    double a_x = f_x / mass;
    double a_y = f_y / mass;


    x += v_x * duration;
    y += v_y * duration;

    v_x += a_x * duration;
    v_y += a_y * duration;
}
void Point::reset(){
    f_x = f_y = 0.0;
}

void Rectangle::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    sf::ConvexShape shape;
    shape.setPointCount(4);

    Vector2D e_1(1.0,0);
    e_1.turn(angle);
    Vector2D e_2 = e_1;
    e_2.turn(pi/2);

    Vector2D p_1 = ( a/2.0 * e_1 - b/2.0 * e_2);
    p_1 = p_1 + pos_Center;
    Vector2D p_2 = ( a/2.0 * e_1 + b/2.0 * e_2);
    p_2 = p_2 + pos_Center;
    Vector2D p_3 = (-a/2.0 * e_1 + b/2.0 * e_2);
    p_3 = p_3 + pos_Center;
    Vector2D p_4 = (-a/2.0 * e_1 - b/2.0 * e_2);
    p_4 = p_4 + pos_Center;

    shape.setPoint(0,sf::Vector2f(p_1.x,target.getSize().y-p_1.y));
    shape.setPoint(1,sf::Vector2f(p_2.x,target.getSize().y-p_2.y));
    shape.setPoint(2,sf::Vector2f(p_3.x,target.getSize().y-p_3.y));
    shape.setPoint(3,sf::Vector2f(p_4.x,target.getSize().y-p_4.y));

    target.draw(shape);
}

Rectangle::Rectangle(double X_Center,double Y_Center,double V_X_CM,double V_Y_CM,double angle,double ang_acc,double a, double b,int (*mass_distribution)(int i,int j)){
    this->pos_Center.x = X_Center;
    this->pos_Center.y = Y_Center;

    this->vel_CM.x = V_X_CM;
    this->vel_CM.y = V_Y_CM;

    this->angle = angle;
    this->ang_acc = ang_acc;

    this->a = a;
    this->b = b;

    torque_TOT = 0.0;

    /// By default
    MASS = 20.0;


    a_N = b_N = 20;

    {

        double C = 0.0;
        double S = 0.0;
        for(int i=1;i<=a_N;i++){
            for(int j=1;j<=b_N;j++){
                S +=mass_distribution(i,j);
            }
        }
        C = MASS / S;

        for(int i=1;i<=a_N;i++){
            for(int j=1;j<=b_N;j++){
                mat_mass[make_pair(i,j)] = C * mass_distribution(i,j);
            }
        }
        /// Calculation of the position of the Center of Mass

        pos_CM.x = 0.0;
        pos_CM.y = 0.0;

        Vector2D e_1(1.0,0.0);
        e_1.turn(angle);

        Vector2D e_2 = e_1;
        e_2.turn(pi/2.0);

        Vector2D left_down = pos_Center - (a/2.0) * e_1 - (b/2.0) * e_2;

        for(int i=1;i<=a_N;i++){
            for(int j=1;j<=b_N;j++){
                Vector2D pos_cube = left_down + (2*i-1)*(a/(2*a_N)) * e_1 + (2*j-1)*(b/(2*b_N)) * e_2;
                pos_CM += pos_cube * mat_mass[make_pair(i,j)] / MASS;
            }
        }

        cout<< pos_Center.x << " " << pos_Center.y << endl;
        cout<< pos_CM.x << " " << pos_CM.y << endl;


    }
    /// Calculation of the Moment of Inertia

    Inertia = 0.0;

    Vector2D e_1(1.0,0.0);
    e_1.turn(angle);
    Vector2D e_2 = e_1;
    e_2.turn(pi/2.0);

    Vector2D left_down = pos_Center - (a/2.0) * e_1 - (b/2.0) * e_2;

    for(int i=1;i<=a_N;i++){
        for(int j=1;j<=b_N;j++){
            Vector2D pos_cube = left_down + (2*i-1)*(a/(2*a_N)) * e_1 + (2*j-1)*(b/(2*b_N)) * e_2;
            Inertia += mat_mass[make_pair(i,j)] * pow((pos_cube - pos_CM).len(),2.0);
        }
    }

}

void Rectangle::integrate(double duration){
    pos_CM += vel_CM * duration;

    Vector2D vel_Center;

    Vector2D e_n = pos_Center - pos_CM;
    e_n.normalize();

    Vector2D e_t = e_n;
    e_t.turn(pi/2.0);

    vel_Center = vel_CM + ang_acc * (pos_Center - pos_CM).len() * e_t;

    pos_Center += vel_Center * duration;

    ///cout << vel_CM.x << " " << vel_CM.y <<  endl;
    ///cout << " " << force_TOT.x << " " << force_TOT.y << endl;
    angle  += ang_acc * duration;

    vel_CM += force_TOT/MASS * duration;
    ang_acc+= torque_TOT/Inertia * duration;

    ///THIS IS IMPORTANT

    Vector2D vel = vel_CM;
    Vector2D dir(1.0,0);
    vel.normalize();

    angle = acos(vel * dir);

    ///cout << (dir^vel) << endl;


    if( (dir^vel) < 0.0 )
        angle = -angle;

    cout << (vel * dir) << endl;
    cout<<" "<< (angle * 180.0 / pi) << endl;
    ///HERE IT ENDS

    force_TOT = Vector2D();
    torque_TOT = 0.0;
}

UniformGravityForRectangle::UniformGravityForRectangle(double g){
    this->g = g;
}

UniformGravityForRectangle::UniformGravityForRectangle(){
    this->g = 10.0;
}

void UniformGravityForRectangle::force_torque_gen(Rectangle& rec){
    rec.force_TOT += Vector2D(0.0,-g) * rec.MASS;


    //////////////
    Vector2D e_1(1.0,0.0);
    e_1.turn(rec.angle);
    Vector2D e_2 = e_1;
    e_2.turn(pi/2.0);

    Vector2D left_down = rec.pos_Center - (rec.a/2.0) * e_1 - (rec.b/2.0) * e_2;



    //////////////

    for(int i=1;i<=rec.a_N;i++){
        for(int j=1;j<=rec.b_N;j++){
            Vector2D pos_cube = left_down + (2*i-1)*(rec.a/(2*rec.a_N)) * e_1 + (2*j-1)*(rec.b/(2*rec.b_N)) * e_2;

            rec.torque_TOT += (pos_cube - rec.pos_CM)^( rec.mat_mass[make_pair(i,j)] * Vector2D(0.0,-g) );

        }
    }

}

void BlackHoleForRectangle::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    double radius = 50.0;
    sf::CircleShape shape(radius);
    shape.setPosition(pos.x-radius,target.getSize().y - pos.y - radius );
    target.draw(shape);
}

BlackHoleForRectangle::BlackHoleForRectangle(double x, double y, double GAMA){
        this->GAMA = GAMA;
        this->pos  = Vector2D(x,y);
    }


void BlackHoleForRectangle::force_torque_gen(Rectangle& rec){
    rec.force_TOT += ((-GAMA * rec.MASS)/(pow((rec.pos_CM - pos).len(),3))) * (rec.pos_CM - pos);

    //////////////
    Vector2D e_1(1.0,0.0);
    e_1.turn(rec.angle);
    Vector2D e_2 = e_1;
    e_2.turn(pi/2.0);

    Vector2D left_down = rec.pos_Center - (rec.a/2.0) * e_1 - (rec.b/2.0) * e_2;



    //////////////

    for(int i=1;i<=rec.a_N;i++){
        for(int j=1;j<=rec.b_N;j++){
            Vector2D pos_cube = left_down + (2*i-1)*(rec.a/(2*rec.a_N)) * e_1 + (2*j-1)*(rec.b/(2*rec.b_N)) * e_2;

            rec.torque_TOT += (pos_cube - rec.pos_CM)^(((-GAMA * rec.mat_mass[make_pair(i,j)])/(pow((pos_cube - pos).len(),3))) * (pos_cube - pos));

        }
    }

}

bool collide(Point& a, Point& b){
    if(a.radius + b.radius > sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) )){
        double r_rel_x = a.x - b.x;
        double r_rel_y = a.y - b.y;

        double v_rel_x = a.v_x - b.v_x;
        double v_rel_y = a.v_y - b.v_y;

        double scalar_product = r_rel_x*v_rel_x + r_rel_y*v_rel_y;
        if(scalar_product < 0){
            return true;
        }

    }
    return false;
}

UniformGravity::UniformGravity(double g){
    this->g = g;
}

UniformGravity::UniformGravity(){
    this->g = 10.0;
}
void UniformGravity::force_generate(Point& point){
    point.f_y -= point.mass * g;
}

BlackHole::BlackHole(double x,double y,double GAMA){
        this->GAMA = GAMA;
        pos.x = x;
        pos.y = y;
    }
void BlackHole::force_generate(Point& point){
    Vector2D pos_p;
    pos_p.x = point.x;
    pos_p.y = point.y;

    Vector2D R = pos_p - pos;

    Vector2D force = ((-GAMA * point.mass)/(pow(R.len(),3))) * R;
    point.f_x += force.get_x();
    point.f_y += force.get_y();
}

void Gravity::add_point(Point& point){
        points.push_back(&point);
    }
void Gravity::add_gravityGenerator(GravityGenerator& gravity_gen){
    gravityGenerators.push_back(&gravity_gen);
}
void Gravity::get_force(){
    for(int i=0;i<points.size();i++){

        for(int j=0;j<gravityGenerators.size();j++)
        {
            gravityGenerators[j]->force_generate(*points[i]);
        }
    }
}

CollisionGenerator::CollisionGenerator(sf::RenderTarget& target){
        W = target.getSize().x;
        H = target.getSize().y;
    }
void CollisionGenerator::add_point(Point& point){
    points.push_back(&point);
}
void CollisionGenerator::resolve_collisions(){
    for(int i=0;i<points.size();i++){
        for(int j=i+1;j<points.size();j++){
            Point* point_a = points[i];
            Point* point_b = points[j];
            if(collide(*point_a, *point_b)){

                Vector2D pos_a(point_a->x,point_a->y);
                Vector2D pos_b(point_b->x,point_b->y);


                /// e_n and e_t vectors
                double eps = 1e-6;

                Vector2D e_n = (pos_a - pos_b);
                while(e_n.len() > 1 + eps ) e_n.normalize();

                ///cout << e_n.len() << endl;

                Vector2D e_t = e_n;
                e_t.turn(pi/2);
                while(e_t.len() > 1 + eps ) e_t.normalize();
                ///cout << e_t.len() << endl;


                ///cout << " Scalar product " << e_n * e_t << endl;

                Vector2D vel_a_initial(point_a->v_x,point_a->v_y);
                Vector2D vel_b_initial(point_b->v_x,point_b->v_y);

                double vel_a_initial_n = (vel_a_initial*e_n);
                double vel_a_initial_t = (vel_a_initial*e_t);

                double vel_b_initial_n = (vel_b_initial*e_n);
                double vel_b_initial_t = (vel_b_initial*e_t);


                ///cout << vel_a_initial_n << " " << vel_b_initial_n << endl;



                double CM_vel =((point_a->mass)*vel_a_initial_n + (point_b->mass)*vel_b_initial_n)/( ( point_a->mass ) + ( point_b->mass ) );

                ///double K = 0.0;

                double vel_a_final_n = 2*CM_vel - vel_a_initial_n;
                double vel_b_final_n = 2*CM_vel - vel_b_initial_n;


                ///double vel_a_final_n = CM_vel - K*(vel_a_initial_n-CM_vel);
                ///double vel_b_final_n = CM_vel - K*(vel_b_initial_n-CM_vel);


                Vector2D vel_a_final = vel_a_final_n * e_n + vel_a_initial_t * e_t;
                Vector2D vel_b_final = vel_b_final_n * e_n + vel_b_initial_t * e_t;

                point_a->v_x = vel_a_final.get_x();
                point_a->v_y = vel_a_final.get_y();

                point_b->v_x = vel_b_final.get_x();
                point_b->v_y = vel_b_final.get_y();






                /**

                Vector2D CM_vel = ((point_a->mass)*vel_a + (point_b->mass)*vel_b)/( (point_a->mass) + (point_b->mass) );

                Vector2D V_a_CM = vel_a - CM_vel;
                Vector2D v_b_CM = vel_b - CM_vel;

                Vector2D n_vel_a = CM_vel - v_a_CM;
                Vector2D n_vel_b = CM_vel - v_b_CM;

                point_a->v_x = n_vel_a.get_x();
                point_a->v_y = n_vel_a.get_y();

                point_b->v_x = n_vel_b.get_x();
                point_b->v_y = n_vel_b.get_y();

                **/



            }
        }
    }
}
void CollisionGenerator::collisions_with_ground(){
    for(int i=0;i<points.size();i++){
        Point* point = points[i];
        ///TO BE CHANGED
        double eps = 1e-6;
        if(point->y + point->radius > H && point->v_y > 0)
        {
            point->v_y = -point->v_y;
        }

        if(point->y - point->radius < 0 && point->v_y < 0)
        {

            if( point->v_y > -eps )
            {
                point->v_y = 0.0;
                point->y = 0.0;
            }
            else
                point->v_y = - 0.9 * point->v_y;

            ///point->v_y = - 0.9 * point->v_y;
            ///cout << point->v_y << endl;
        }

        if(point->x + point->radius > W && point->v_x > 0){
            point->v_x = -point->v_x;
        }

        if(point->x - point->radius < 0 && point->v_x < 0){
            point->v_x = -point->v_x;
        }

    }
}

int distr(int i,int j)
{
    return i*i;
}

const double pi = 3.141592653589;