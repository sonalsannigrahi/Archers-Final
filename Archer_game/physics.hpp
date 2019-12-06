#ifndef PHYSICS_HPP_INCLUDED
#define PHYSICS_HPP_INCLUDED

typedef double real;



class Vector{
private:
    real x;
    real y;
    real z;
public:
    Point(real _x, real _y, real _z) : x(_x), y(_y), z(_z) {}
    Vector cross_product(Vector& other);
    real scalar_product(Vector& other);
};

class ConvexPolygon{
private:
    vector<Vector>points;
public:
    /// Checks whether it is really a convex polygon
    bool check();

    ConvexPolygon intersect(ConvexPolygon& other);

};


class Object{
private:
    real CM_x;
    real CM_y;
    real CM_z;

    ConvexPolygon shape;

public:

};

#endif // PHYSICS_HPP_INCLUDED
