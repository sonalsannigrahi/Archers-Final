#ifndef VECTOR_2D_HPP_INCLUDED
#define VECTOR_2D_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

const double pi = 3.141592653589793;

double fRand(double fMin, double fMax);

class Vector2D
{
private:
    double x;
    double y;
public:
    Vector2D();
    Vector2D(double x, double y);
    Vector2D(const Vector2D& other);
    double get_x() const ;
    double get_y() const ;

    void set_x(double x);
    void set_y(double y);

    double len();

    void normalize();
    void turn(double angle);

    Vector2D operator+(const Vector2D& other);
    Vector2D operator-(const Vector2D& other);

    Vector2D operator*(double k);
    Vector2D operator/(double k);

    Vector2D& operator+=(const Vector2D& other);
    Vector2D& operator-=(const Vector2D& other);
    ///Scalar Product
    double operator*(const Vector2D& other);
    ///Vector product in 2D
    double operator^(const Vector2D& other);

    friend Vector2D operator*(double k, Vector2D v);

};

#endif // VECTOR_2D_HPP_INCLUDED
