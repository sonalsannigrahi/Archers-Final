#ifndef RECTANGLE_CLASS_HPP_INCLUDED
#define RECTANGLE_CLASS_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

#include "VECTOR_2D.hpp"

class Rectangle: public sf::Drawable
{
private:
    Vector2D pos_CM;
    Vector2D vel_CM;

    double angle;
    double angle_VEL;

    double MASS;
    double Inertia;

    double length;
    double width;

    Vector2D force_TOT;
    double torque_TOT;

    int a_N;
    int b_N;
    std::map<std::pair<int,int>, double> mat_mass;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Rectangle(Vector2D pos_CM,Vector2D vel_CM,double angle,double angle_VEL,double length,double width,double MASS,double (*mass_distribution)(int i,int j));
};



#endif // RECTANGLE_CLASS_HPP_INCLUDED
