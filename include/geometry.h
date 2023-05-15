#pragma once

const double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;

class Circle {
public:
    double radius;
    double area();
    double circumference();
};

class CartesianPoint {
public:
    double x;
    double y;
};

class PolarPoint {
public:
    double r;
    double theta;
};


/*
*  Compute the area of a circle
*/
double areaOfCircle(double r);

/*
*  Compute the circumference of a circle
*/
double circumferenceOfCircle(double r);

/*
*   Converts Cartesian coordinates to polar coordinates. Note this
*   changes r and theta.
*/
PolarPoint cartesianToPolar(const CartesianPoint& );
/*
*  Converts polar coordinates to Cartesian coordinates. Note this
*  changes x and y.
*/
CartesianPoint polarToCartesian(const PolarPoint& );
/*
* Test suite
*/
void testGeometry();
