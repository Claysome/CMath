#pragma once

const double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;

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
void cartesianToPolar(double x, double y, double& r, double& theta);

/*
*  Converts polar coordinates to Cartesian coordinates. Note this
*  changes x and y.
*/
void polarToCartesian(double r, double theta, double& x, double& y);

/*
* Test suite
*/
void testGeometry();
