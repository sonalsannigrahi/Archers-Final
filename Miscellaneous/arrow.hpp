#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>
#include "physics.hpp"
#include <string>


class Arrow: public Rectangle{
    public:
        //need to include the files for sprites
        sf::Texture texture;
        bool shot = false;
        //File included will depend on arrow types(not yet implemented but will be used for future levels)

        double a_x; //acceleration in the x
        double a_y = 9.8; //acceleration in the y, by default is gravity

        UniformGravityForRectangle rec_grav = UniformGravityForRectangle(9.8);

        double damage = 0.5; //default value
        
    public:
        Arrow();
        virtual ~Arrow(){};
        Arrow(double X_CM, double Y_CM, double V_X_CM, double V_Y_CM, double angle, double ang_acc, double a, double b, double m, std::string filename);
        //X_CM = x coordinate of center of mass, V_X_CM = x comp of velociy, angle = angle of roation, a = width, b = height
        //note, a and b might be switched, unclear from physics.cpp written by the physics team
        
        void update(double time);
        void shoot(double vel);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void changeAngle(double alpha);
        double inflictDamage();
};
