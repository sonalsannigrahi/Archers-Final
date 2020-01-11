#include "physics.hpp"

Vector2D::Vector2D(double x = 0.0, double y = 0.0){
        this->x = x;
        this->y = y;
    }
double Vector2D::get_x(){
    return x;
}
double Vector2D::get_y(){
    return y;
}
double Vector2D::len(){
    double ans = sqrt(x*x + y*y);
    return ans;
}
void Vector2D::normalize(){
    if( this->len() !=0 ){
        x = x / this->len();
        y = y / this->len();
    }
}
void Vector2D::turn(double angle)
{
    /// angles in radians
    double n_x = cos(angle) * x - sin(angle) * y;
    double n_y = sin(angle) * x + cos(angle) * y;
    x = n_x;
    y = n_y;
}


Vector2D Vector2D::operator/(double k){
    Vector2D ans;
    ans.x = x/k;
    ans.y = y/k;
    return ans;
}
Vector2D Vector2D::operator+(Vector2D other){
    Vector2D ans;
    ans.x = this->x + other.x;
    ans.y = this->y + other.y;
    return ans;
}
Vector2D Vector2D::operator-(Vector2D other){
    Vector2D ans;
    ans.x = this->x - other.x;
    ans.y = this->y - other.y;
    return ans;
}
Vector2D Vector2D::operator*(double k){
    Vector2D ans;
    ans.x = (this->x)*k;
    ans.y = (this->y)*k;
    return ans;
}
Vector2D& Vector2D::operator+=(const Vector2D& other){
    this->x += other.x;
    this->y += other.y;
    return *this;
}
double Vector2D::operator*(Vector2D other){
    double ans = (this->x)*(other.x) + (this->y)*(other.y);
    return ans;
}
double Vector2D::operator^(Vector2D other){
    return this->x * other.y - this->y * other.x;
}
Vector2D operator*(double k, Vector2D v)
{
    return v*k;
}
