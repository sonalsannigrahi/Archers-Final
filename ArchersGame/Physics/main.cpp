#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class PointMass;
class Vector2D{
public:
    double x;
    double y;
    Vector2D(){};

    Vector2D(double x1,double y1){
        x = x1;
        y = y1;
    }

    friend Vector2D operator*(double k,Vector2D v);

    Vector2D operator+(Vector2D &other){
        Vector2D ans;
        ans.x = this->x + other.x;
        ans.y = this->y + other.y;
        return ans;
    }
    Vector2D operator-(Vector2D &other){
        Vector2D ans;
        ans.x = this->x - other.x;
        ans.y = this->y - other.y;
        return ans;
    }
    

    

    double magnitude(){
        return sqrt( (this->x)*(this->x) + (this->y)*(this->y) );
    }
};

double operator* (Vector2D a, Vector2D b){
        return (a.x * b.x) + (a.y * b.y);
    }
double operator^(Vector2D a, Vector2D b){ // opperator that calculates the vector product between two vectors
        return a.x*b.y-a.y*b.x;
    }

Vector2D operator*(double k,Vector2D v)
{
    Vector2D ans;
    ans.x = k*(v.x);
    ans.y = k*(v.y);
    return ans;
}

double cos(Vector2D &other){ //function that calculates the cossine between two vectors
    Vector2D ans;
    return (ans.magnitude()*ans.magnitude()+other.magnitude()*other.magnitude()-(ans-other).magnitude()*(ans-other).magnitude())/(2*ans.magnitude()*other.magnitude());
}

double sin(Vector2D &other){ //function that calculates sin between two angles
    Vector2D ans;
    return (ans^other)*(1.0/(ans.magnitude()*other.magnitude()));
}



class AirResistance:public Force{
private:
    Vector2D r;
public:
    AirResistance(PointMass m){
        r = 0.5*0.47*1.225*(m.radius * m.radius * 3.142) * m.vel.magnitude()*(-1)*m.vel;
    }
    virtual Vector2D get_force(PointMass &m){
        Vector2D _force = 0.5*0.47*1.225*(m.radius * m.radius * 3.142) * m.vel.magnitude()*(-1)*m.vel;
        return _force;
    }
};



class Force{
    virtual Vector2D get_force(PointMass &  point) = 0;
};



class ConstantGravity:public Force{
private:
    Vector2D g;
public:
    ConstantGravity(vector2D _g){
        g = _g;
    }
    virtual Vector2D get_force(PointMass & point){
        Vector2D _force = point.mass * g;
        return _force;
    }
};

class BlackHole:public PointMass{
    vel=0;
    sum_forces=0;//check if need Vector2D
    //Add function to kill object if it intersects the blackhole

};

class ForceGenerator{
private:
    vector<PointMass*> points;
    vector<Force*> forces;
public:
    void act(){
        for(int i=0;i<points.size();i++){
            for(int j=0;j<forces.size();j++){
                PointMass* point = points[i];
                Force* force = forces[j];

                point->sum_forces = point->sum_forces + force->get_force(point);

            }
        }
    }
};

class CollisionGenerator{
public:
    vector<PointMass*> points;
public:
    CollisionGenerator(){};
    void add_point(PointMass* point){
        points.push_back( point );
    }
    void resolve_collisions(){
        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                //Collision between ith and jth objects;
                

                if( intersect(*points[i],*points[j]) ){
                    Vector2D CM_VEL = (*points[i]).mass * (*points[i]).vel + (*points[j]).mass * (*points[j]).vel;
                    CM_VEL = CM_VEL/( (*points[i]).mass + (*points[j]).mass );

                    Vector2D V = (*points[i]).vel - (*points[j]).vel;

                    Vector2D V_i_CM = -(*points[j]).mass/((*points[i]).mass + (*points[j]).mass) * V; //velocity_i after collision CM frame
                    Vector2D V_j_CM = (*points[i]).mass/((*points[i]).mass + (*points[j]).mass) * V; //velocity_j after collision CM frame

                    ///TODO just say that the final velocity will be equal to vcm+vrel (for both)

                }
            }
        }
    }
};


class PointMass {
public:
    Vector2D pos;
    Vector2D vel;
    Vector2D sum_forces;
    double mass;
    double radius;
    friend bool intersect(PointMass a, PointMass b);
    friend Force;
public:
    PointMass(double _x, double _y, double _mass, double _radius):
        x(_x),y(_y),mass(_mass),radius(_radius){
            sum_forces.x = 0.0;
            sum_forces.y = 0.0;
        }

    void integrate(double duration)
    {
        Vector2D acc = (1.0/mass)*sum_forces;
        vel = vel + duration*acc;
        pos = pos + duration*vel;

        sum_forces.x = 0.0;
        sum_forces.y = 0.0;
    }
};

bool intersect(PointMass a, PointMass b)
{
    if( a.radius + b.radius > (a.pos-b.pos).magnitude() )
        return true;
    else
        return false;
}



int main()
{
    Vector2D a = Vector2D(3,4);
    Vector2D b = Vector2D(5,6);
    double c = a * b;
    std::cout << c << std::endl;
    return 0;
}

/**
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Gravity;

class Point: public sf::Drawable{
private:

    double mass;

    double x;
    double y;

    double v_x;
    double v_y;

    double f_x;
    double f_y;

    double radius;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        sf::CircleShape shape(radius);
        shape.setPosition(x,target.getSize().y - y);
        target.draw(shape);
    }
public:

    friend Gravity;

    Point(double _mass, double _x, double _y, double _v_x, double _v_y, double _radius){
        mass = _mass;

        x = _x;
        y = _y;

        v_x = _v_x;
        v_y = _v_y;

        f_x = 0.0;
        f_y = 0.0;

        radius = _radius;
    }
    void integrate(double duration){
        double a_x = f_x / mass;
        double a_y = f_y / mass;

        v_x += a_x * duration;
        v_y += a_y * duration;

        x += v_x * duration;
        y += v_y * duration;

    }
    void reset(){
        f_x = f_y = 0.0;
    }
};

class Gravity{
private:
    double g = 10.0;
public:
    void get_force(Point& point)
    {
        point.f_y -= point.mass * g;
    }

};
/// To do
/**

Collisions with earth
convex shape
black hole
Collisions with each other





int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!",sf::Style::Default);

    sf::CircleShape shape(100.f);

    Point point(20.0, -50.0, 50.0, 15.0, 70.0, 50.0);
    Gravity gravity;


    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        gravity.get_force(point);

        float duration = clock.getElapsedTime().asSeconds() * 10.0;
        clock.restart();

        point.integrate(duration);

        window.clear();
        window.draw(point);
        window.display();

        point.reset();
    }

    return 0;
}
**/

