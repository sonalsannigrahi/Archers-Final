#include<bits/stdc++.h>

using namespace std;

class PointMass;
class Vector2D{
public:
    double x;
    double y;
    Vector2D(){};

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


Vector2D operator*(double k,Vector2D v)
{
    Vector2D ans;
    ans.x = k*(v.x);
    ans.y = k*(v.y);
    return ans;
}




class Force{
    virtual Vector2D get_force(int x,int y) = 0;
};



class ConstantGravity:public Force{
private:
    double g;
public:
    ConstantGravity(){
        g = 10.0;
    }
    virtual Vector2D get_force(double x,double y){
        Vector2D ans;
        ans.x = 0.0;
        ans.y = -g;
    }
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

                point->sum_forces = point->sum_forces + force->get_force(0.0,0.0);

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
                /**
                Collision between ith and jth objects;
                **/

                if( intersect(*points[i],*points[j]) ){
                    Vector2D CM_VEL = (*points[i])*mass * (*points[i]).vel + (*points[j])*mass * (*points[j]).vel;
                    Vector2D CM_VEL = 1.0/( (*points[i]).mass + (*points[j]).mass );

                    Vector2D V = (*points[i]).vel - (*points[j]).vel;

                    Vector2D V_i_CM = (*points[j])*mass/((*points[i]).mass + (*points[j]).mass) * V;
                    Vector2D V_j_CM = (-*points[i])*mass/((*points[i]).mass + (*points[j]).mass) * V;

                    ///TODO

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
    return 0;
}
