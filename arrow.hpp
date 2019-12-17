#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>
#include "physics.cpp"


class Arrow: public Rectangle{
    private:
        //need to include the files for sprites
        sf::Texture texture;
        bool shot = false;
        //File included will depend on arrow types(not yet implemented but will be used for future levels)
        
    public:
        Arrow();
        Arrow(double X_CM, double Y_CM, double V_X_CM, double V_Y_CM, double angle, double ang_acc, double a, double b, std::string filename);
        //X_CM = x coordinate of center of mass, V_X_CM = x comp of velociy, angle = angle of roation, a = width, b = height
        //note, a and b might be switched, unclear from physics.cpp written by the physics team
        
        void update(double time);
        void shoot();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void changeAngle(double alpha);
};
