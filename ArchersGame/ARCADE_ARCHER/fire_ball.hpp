#ifndef FIRE_BALL_HPP_INCLUDED
#define FIRE_BALL_HPP_INCLUDED

#include "VECTOR_2D.hpp"
#include<SFML/Graphics.hpp>

class CollisionGenerator;

class FIRE_BALL: public sf::Drawable{
private:
    double MASS;
    double RADIUS;

    Vector2D Pos;
    Vector2D Vel;

    Vector2D ForceTot;

    sf::Color color;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        sf::CircleShape shape(RADIUS);

        shape.setFillColor(color);


        shape.setPosition(Pos.get_x()-RADIUS,target.getSize().y - (Pos.get_y() + RADIUS) );
        target.draw(shape);


        double W = target.getSize().x;
        double H = target.getSize().y;

        int L = 4;
        for(int i = (int)floor((Pos.get_x()-RADIUS)/L); i <= (int)ceil((Pos.get_x()+RADIUS)/L); i++){
            for(int j = (int)floor((Pos.get_y()-RADIUS)/L); j <= (int)ceil((Pos.get_y()+RADIUS)/L); j++){
                double center_x = (i - 0.5) * L;
                double center_y = (j - 0.5) * L;
                double dist = sqrt(pow(center_x - Pos.get_x(),2.0)+pow(center_y - Pos.get_y(),2.0));
                if(dist <= RADIUS){
                    sf::RectangleShape shape(sf::Vector2f(L,L));
                    shape.setFillColor(color);
                    shape.setPosition(center_x - L/2, H - (center_y + L/2));
                    target.draw(shape);
                }
            }
        }


    }

public:

    friend CollisionGenerator;

    FIRE_BALL(double MASS, double RADIUS, Vector2D Pos, Vector2D Vel,sf::Color color);

    double getMass() const;
    double getRadius() const;

    Vector2D getPos() const;
    Vector2D getVel() const;
    void ResetForce();
    void updateForceTot(Vector2D AddForce);
    void update(double duration);
};

#endif // FIRE_BALL_HPP_INCLUDED
