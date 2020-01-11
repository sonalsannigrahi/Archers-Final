#include "VECTOR_2D.hpp"

Vector2D::Vector2D()
{
    this->x = 0.0;
    this->y = 0.0;
}

Vector2D::Vector2D(double x = 0.0, double y = 0.0)
{
    this->x = x;
    this->y = y;
}
Vector2D::Vector2D(const Vector2D& other)
{
    this->x = other.get_x();
    this->y = other.get_y();
}




double Vector2D::get_x() const {
    return x;
}
double Vector2D::get_y() const {
    return y;
}

void Vector2D::set_x(double x)
{
    this->x = x;
}

void Vector2D::set_y(double y)
{
    this->y = y;
}


double Vector2D::len(){
    double len = sqrt(x*x+y*y);
    return len;
}
void Vector2D::normalize(){
    double eps = 1e-6;

    if(this->len() < eps){
        return;
    }

    while( !( (this->len() > 1 - eps) && (this->len() < 1 + eps) ) ){
        x = x / this->len();
        y = y / this->len();
    }
}
void Vector2D::turn(double angle){
    double x_n = cos(angle) * x - sin(angle) * y;
    double y_n = sin(angle) * x + cos(angle) * y;

    this->x = x_n;
    this->y = y_n;
}

Vector2D Vector2D::operator+(const Vector2D& other){
    Vector2D ans(*this);

    ans.x += other.get_x();
    ans.y += other.get_y();

    return ans;
}

Vector2D Vector2D::operator-(const Vector2D& other){
    Vector2D ans(*this);

    ans.x -= other.get_x();
    ans.y -= other.get_y();

    return ans;
}

Vector2D Vector2D::operator*(double k)
{
    Vector2D ans(*this);
    ans.x*=k;
    ans.y*=k;
    return ans;
}
Vector2D Vector2D::operator/(double k)
{
    Vector2D ans(*this);
    ans.x/=k;
    ans.y/=k;
    return ans;
}

Vector2D& Vector2D::operator+=(const Vector2D& other)
{
    this->x += other.get_x();
    this->y += other.get_y();

    return (*this);
}
Vector2D& Vector2D::operator-=(const Vector2D& other)
{
    this->x -= other.get_x();
    this->y -= other.get_y();

    return (*this);
}


double Vector2D::operator*(const Vector2D& other)
{
    return (this->x) * other.get_x() + (this->y) * other.get_y();
}
double Vector2D::operator^(const Vector2D& other)
{
    return (this->x) * other.get_y() - (this->y) * other.get_x();
}

Vector2D operator*(double k, Vector2D v)
{
    return v*k;
}



