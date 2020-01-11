#ifndef PHYSICS_HPP_INCLUDED
#define PHYSICS_HPP_INCLUDED

///BEGINNING OF THE HEADER FILE

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>



///CONSTANTS
double pi = 3.141592653589;


///VECTOR2D CLASS

class Vector2D{
public:
    double x;
    double y;
public:
    Vector2D(double x = 0.0, double y = 0.0);
    double get_x();
    double get_y();
    
    double len();
    void normalize();
    
    void turn(double angle);


    Vector2D operator/(double k);
    Vector2D operator+(Vector2D other);
    Vector2D operator-(Vector2D other);
    Vector2D operator*(double k);
    Vector2D& operator+=(const Vector2D& other);

    friend Vector2D operator*(double k, Vector2D v);
    
    double operator*(Vector2D other);
    double operator^(Vector2D other);
};





#endif