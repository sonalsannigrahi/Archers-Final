#include <SFML/Graphics.hpp>
#include "RECTANGLE_CLASS.hpp"

const double pi = 3.141592653589793;

void Rectangle::Rectangle(Vector2D pos_CM,Vector2D vel_CM,double angle,double angle_VEL,double length,double width,double MASS,double (*mass_distribution)(int i,int j))
{
    this->pos_CM = pos_CM;
    this->vel_CM = vel_CM;

    this->angle = angle;
    this->angle_VEL = angle_VEL_acc;

    this->length = length;
    this->width = width;

    this->MASS = MASS;
    ///By Default
    a_N = b_N = 20;

    torque_TOT = 0.0;
    force_TOT = Vector2D();
    {

        double C = 0.0;
        double S = 0.0;
        for(int i=1;i<=a_N;i++){
            for(int j=1;j<=b_N;j++){
                S +=mass_distribution(i,j);
            }
        }
        C = MASS / S;

        for(int i=1;i<=a_N;i++){
            for(int j=1;j<=b_N;j++){
                mat_mass[make_pair(i,j)] = C * mass_distribution(i,j);
            }
        }
        /// Calculation of the position of the Center of Mass

        pos_CM.x = 0.0;
        pos_CM.y = 0.0;

        Vector2D e_1(1.0,0.0);
        e_1.turn(angle);

        Vector2D e_2 = e_1;
        e_2.turn(pi/2.0);

        Vector2D left_down = pos_CM - (a/2.0) * e_1 - (b/2.0) * e_2;

        for(int i=1;i<=a_N;i++){
            for(int j=1;j<=b_N;j++){
                Vector2D pos_cube = left_down + (2*i-1)*(a/(2*a_N)) * e_1 + (2*j-1)*(b/(2*b_N)) * e_2;
                pos_CM += pos_cube * mat_mass[make_pair(i,j)] / MASS;
            }
        }

    }
    /// Calculation of the Moment of Inertia

    Inertia = 0.0;

    Vector2D e_1(1.0,0.0);
    e_1.turn(angle);
    Vector2D e_2 = e_1;
    e_2.turn(pi/2.0);

    Vector2D left_down = pos_Center - (a/2.0) * e_1 - (b/2.0) * e_2;

    for(int i=1;i<=a_N;i++){
        for(int j=1;j<=b_N;j++){
            Vector2D pos_cube = left_down + (2*i-1)*(a/(2*a_N)) * e_1 + (2*j-1)*(b/(2*b_N)) * e_2;
            Inertia += mat_mass[make_pair(i,j)] * pow((pos_cube - pos_CM).len(),2.0);
        }
    }
}

void Rectangle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::ConvexShape shape;
    shape.setPointCount(4);

    Vector2D e_1(1.0,0);
    e_1.turn(angle);
    Vector2D e_2 = e_1;
    e_2.turn(pi/2);

    Vector2D p_1 = ( length/2.0 * e_1 - width/2.0 * e_2);
    p_1 = p_1 + pos_CM;
    Vector2D p_2 = ( length/2.0 * e_1 + width/2.0 * e_2);
    p_2 = p_2 + pos_CM;
    Vector2D p_3 = (-length/2.0 * e_1 + width/2.0 * e_2);
    p_3 = p_3 + pos_CM;
    Vector2D p_4 = (-length/2.0 * e_1 - width/2.0 * e_2);
    p_4 = p_4 + pos_CM;

    shape.setPoint(0,sf::Vector2f(p_1.get_x(),target.getSize().y-p_1.get_y()));
    shape.setPoint(1,sf::Vector2f(p_2.get_x(),target.getSize().y-p_2.get_y()));
    shape.setPoint(2,sf::Vector2f(p_3.get_x(),target.getSize().y-p_3.get_y()));
    shape.setPoint(3,sf::Vector2f(p_4.get_x(),target.getSize().y-p_4.get_y()));

    target.draw(shape);
}
