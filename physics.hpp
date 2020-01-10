#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>

#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


extern const double pi;// = 3.141592653589;


class Gravity;
class GravityGenerator;
class CollisionGenerator;




class Vector2D{
public:
    double x;
    double y;
public:
    Vector2D();
    Vector2D(double x, double y);
    double get_x();
    double get_y();
    double len();
    void normalize();
    void turn(double angle);
    Vector2D operator/(double k);
    Vector2D operator+(Vector2D other);
    Vector2D operator-(Vector2D other);
    inline Vector2D operator*(double k);
    Vector2D& operator+=(const Vector2D& other);
    friend Vector2D operator*(double k, Vector2D v);
    double operator*(Vector2D other);
    double operator^(Vector2D other);
};

Vector2D operator*(double k, Vector2D v);

class Point: public sf::Drawable{
public:

    double mass;

    double x;
    double y;

    double v_x;
    double v_y;

    double f_x;
    double f_y;

    double radius;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    friend bool collide(Point& a, Point& b);

    friend Gravity;
    friend GravityGenerator;
    friend CollisionGenerator;

    Point(double _mass, double _x, double _y, double _v_x, double _v_y, double _radius);

    double energy();
    void integrate(double duration);
    void reset();
};

class Rectangle: public sf::Drawable{
///private:
public:
    Vector2D pos_Center;
    Vector2D pos_CM;
    Vector2D vel_CM;
    Vector2D force_TOT;

    double torque_TOT;
    double Inertia;

    double angle;
    double ang_acc;
    double a;
    double b;

    double MASS;

    int a_N;
    int b_N;
    map< pair<int,int>, double> mat_mass;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Rectangle(double X_Center,double Y_Center,double V_X_CM,double V_Y_CM,double angle,double ang_acc,double a, double b,int (*mass_distribution)(int i,int j));
    void integrate(double duration);

};

class GravityForRectangle{
public:
    virtual void force_torque_gen(Rectangle& rec) = 0;
};

class UniformGravityForRectangle: public GravityForRectangle{
private:
    double g;
public:
    UniformGravityForRectangle(double g);
    UniformGravityForRectangle();
    virtual void force_torque_gen(Rectangle& rec);
};

class BlackHoleForRectangle: public GravityForRectangle,public sf::Drawable{
private:
    Vector2D pos;
    double GAMA;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    BlackHoleForRectangle(double x, double y, double GAMA);
    virtual void force_torque_gen(Rectangle& rec);
};

bool collide(Point& a, Point& b);

class GravityGenerator{
private:

public:
    virtual void force_generate(Point& point) = 0;
};

class UniformGravity:public GravityGenerator{
private:
    double g;
public:
    UniformGravity(double g);
    UniformGravity();
    virtual void force_generate(Point& point);
};

class BlackHole:public GravityGenerator{
private:
    Vector2D pos;
    double GAMA;
public:
    BlackHole(double x,double y,double GAMA);
    virtual void force_generate(Point& point);
};

class Gravity{
private:
    vector<Point*> points;
    vector<GravityGenerator*> gravityGenerators;
public:
    void add_point(Point& point);
    void add_gravityGenerator(GravityGenerator& gravity_gen);
    void get_force();
};

class CollisionGenerator{
public:
    CollisionGenerator(sf::RenderTarget& target);
    void add_point(Point& point);
    void resolve_collisions();
    void collisions_with_ground();
private:
    double W;
    double H;
    vector<Point*> points;
};

int distr(int i,int j);
