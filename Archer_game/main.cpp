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

Vector2D operator*(double k,Vector2D v)
{
    Vector2D ans;
    ans.x = k*(v.x);
    ans.y = k*(v.y);
    return ans;
}

double cos(Vector2D &other){ //function that calculates the cossine between two vectors
    Vector2D ans;
    return (magnitude(ans)*magnitude(ans)+magnitude(other)*magnitude(other)-magnitude(ans-other)*magnitude(ans-other))/(2*magnitude(ans)*magnitude(other));
}

double sin(Vector2D &other){ //function that calculates sin between two angles
    Vector2D ans;
    return (ans^other)/magnitude(ans)*magnitude(other);
}

Vector2D operator^(Vector2D &other){ // opperator that calculates the vector product between two vectors
    Vector2D ans;
    return ans.x*other.y-ans.y*other.x;
}




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



