#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Gravity;
class CollisionGenerator;

class Vector2D{
private:
    double x;
    double y;
public:
    Vector2D(){}
    Vector2D(double x, double y){
        this->x = x;
        this->y = y;
    }
    double get_x(){
        return x;
    }
    double get_y(){
        return y;
    }
    double len(){
        double ans = sqrt(x*x + y*y);
        return ans;
    }
    Vector2D operator/(double k){
        Vector2D ans;
        ans.x = x/k;
        ans.y = y/k;
        return ans;
    }
    Vector2D operator+(Vector2D other){
        Vector2D ans;
        ans.x = this->x + other.x;
        ans.y = this->y + other.y;
        return ans;
    }
    Vector2D operator-(Vector2D other){
        Vector2D ans;
        ans.x = this->x - other.x;
        ans.y = this->y - other.y;
        return ans;
    }
    Vector2D operator*(double k){
        Vector2D ans;
        ans.x = (this->x)*k;
        ans.y = (this->y)*k;
        return ans;
    }
    friend Vector2D operator*(double k, Vector2D v);
    double operator*(Vector2D& other){
        double ans = (this->x)*(other.x) + (this->y)*(other.y);
        return ans;
    }
};
Vector2D operator*(double k, Vector2D v)
{
    return v*k;
}


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
        shape.setPosition(x-radius,target.getSize().y - y - radius );
        target.draw(shape);
    }
public:
    friend bool collide(Point& a, Point& b);
    friend Gravity;
    friend CollisionGenerator;

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

bool collide(Point& a, Point& b)
{
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


class Gravity{
private:
    double g = 10.0;
    vector<Point*> points;
public:
    void add_point(Point& point){
        points.push_back(&point);
    }
    void get_force()
    {
        for(int i=0;i<points.size();i++){
            points[i]->f_y -= points[i]->mass * g;
        }
    }

};

//----------------------------Coded by Nicolas (05/12)------------------------------------//
//I used intercation with the Point class because I do not know which of the two codes we are going to follow, hence, if PointMass was the correct one, just change Points to PointMass
double G //Gravitational constant to be changed to make the game more interesting

class BlackHole{
private:
    double x;
    double y;
    double mass;
    double radius; //What if we do a relation between radius and mass? In physics a good approach is to do m proportional to area**2
    vector<Point*> points;
public:
    double get_x(){
        return x;
    }
    double get_y(){
        return y;
    }
    double get_mass(){
        return mass
    }
    double get_radius(){
        return radius
    }
    Vector2D force(BlackHole black, Point point){ //Computes the force between a PointMass and a BlackHole
        dx=black.x-point.get_x();
        dy=black.x-point.get_y();
        d=sqrt((dx*dx)+(dy*dy));
        Force_Mod=(G*black.mass*point.get_mass())/(d*d);
        Vector2D ResultingForce;
        ResultingForce(Force_Mod*(dx/d),Force_Mod*dy/d);
        return ResultingForce;
    }
    void get_force(){ //Compute the force each PointMass feel from all the BlackHoles
        vector<BlackHole*> blackholes; //Takes all the BlackHoles in the game
        for(int i=0;i<points.size();i++){
            for(int j=0;j<blackholes.size(),j++)
                points[i]->f_x+=force(blackholes[j],points[i]).get_x();
                points[i]->f_y+=force(blackholes[j],points[i]).get_y();
        }
    }
    //Still have to add function to delete object once it touches a BlackHole
}
//-------
class ArrowObject{
private:
    double p1;
    double p2;//It is enough to just have two points (it is a rectangle) as it will be a square (maybe a third for the tip)
    double mass;//Better to break into different objects
public:
    double get_x(){
        return x;
    }
    double get_y(){
        return y;
    }
    double get_mass(){
        return mass
    }
}
//-------
//-----------------------------Coded by Nicolas (05/12)---------------------------------------//


class CollisionGenerator{
public:
    CollisionGenerator(sf::RenderTarget& target){
        W = target.getSize().x;
        H = target.getSize().y;
    }
    void add_point(Point& point){
        points.push_back(&point);
    }
    void resolve_collisions(){
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                Point* point_a = points[i];
                Point* point_b = points[j];
                if(collide(*point_a, *point_b)){
                    /**
                    Vector2D pos_a(point_a->x,point_a->y);
                    Vector2D pos_b(point_b->x,point_b->y);
                    **/
                    Vector2D vel_a(point_a->v_x,point_a->v_y);
                    Vector2D vel_b(point_b->v_x,point_b->v_y);

                    Vector2D CM_vel = ((point_a->mass)*vel_a + (point_b->mass)*vel_b)/( (point_a->mass) + (point_b->mass) );

                    Vector2D V_a_CM = vel_a - CM_vel;
                    Vector2D v_b_CM = vel_b - CM_vel;

                    Vector2D n_vel_a = CM_vel - V_a_CM;
                    Vector2D n_vel_b = CM_vel - v_b_CM;

                    point_a->v_x = n_vel_a.get_x();
                    point_a->v_y = n_vel_a.get_y();

                    point_b->v_x = n_vel_b.get_x();
                    point_b->v_y = n_vel_b.get_y();

                }
            }
        }
    }
    void collisions_with_ground(){
        for(int i=0;i<points.size();i++){
            Point* point = points[i];
            ///TO BE CHANGED
            if(point->y - point->radius < 0 && point->v_y < 0)
            {
                point->v_y = -point->v_y;
            }

            if(point->x + point->radius > W && point->v_x > 0){
                point->v_x = -point->v_x;
            }

            if(point->x - point->radius < 0 && point->v_x < 0){
                point->v_x = -point->v_x;
            }
        }
    }

private:
    double W;
    double H;
    vector<Point*> points;
};

/// To do
/**

Collisions with earth
convex shape
black hole
Collisions with each other


**/



int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!",sf::Style::Default);

    sf::CircleShape shape(100.f);

    ///Point point(20.0, 200.0, 100.0, 10.0, 40.0, 50.0);

    Gravity gravity;
    ///gravity.add_point(point);



    CollisionGenerator CGenerator(window);
    ///CGenerator.add_point(point);

    vector<Point*> points;
    ///points.push_back(&point);

    sf::Clock clock;
    bool flag = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && flag == false){
            double x = sf::Mouse::getPosition(window).x;
            double y = sf::Mouse::getPosition(window).y;
            y = window.getSize().y - y;
            cout<<x<<" "<<y<<endl;
            Point* point = new Point(20.0, x, y, 10.0, 20.0, 50.0);
            points.push_back(point);
            gravity.add_point(*point);
            CGenerator.add_point(*point);
            flag = true;
        }
        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            flag = false;
        }
        CGenerator.collisions_with_ground();
        CGenerator.resolve_collisions();
        gravity.get_force();

        float duration = clock.getElapsedTime().asSeconds() * 10.0;
        clock.restart();

        for(int i=0;i<points.size();i++){
            points[i]->integrate(duration);
        }

        window.clear();

        for(int i=0;i<points.size();i++){
            window.draw(*points[i]);
        }

        window.display();

        for(int i=0;i<points.size();i++){
            points[i]->reset();
        }
    }

    return 0;
}

