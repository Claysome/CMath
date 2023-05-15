#include "stdafx.h"
#include "geometry.h"
#include "testing.h"


/*
* Computes the area of a circle
*/
double Circle::area() {
    return PI*radius*radius;
}

/*
* Computes the circumference of a circle
*/
double Circle::circumference() {
    return 2*PI*radius;
}

/*
*   Converts Cartesian coordinates to polar coordinates. Note this
*   changes r and theta.
*/
PolarPoint cartesianToPolar(const CartesianPoint& c) {
    PolarPoint p;
    p.r = sqrt(c.x*c.x+c.y*c.y);
    if (c.y==0.0) {
        if (c.x>=0.0) {
            p.theta = 0.0;
        }
        else if (c.x<0.0) {
            p.theta = -PI;
        }
    }
    else {
        p.theta = acos(c.x/p.r);
        if (c.y<0) {
            p.theta = -p.theta;
        }
    }
}

/*
*  Converts polar coordinates to Cartesian coordinates. Note this
*  changes x and y.
*/
CartesianPoint polarToCartesian(const PolarPoint& p) {
    CartesianPoint c;
    c.x = p.r*cos(p.theta);
    c.y = p.r*sin(p.theta);
    return c;
}


/////////////////////////////////////////////////
//
//  Geometry tests
//
/////////////////////////////////////////////////


static void testUsage() {
    CartesianPoint p;
    p.x = 1.0;
    p.y = 1.0;
    std::cout << "Coordinates (" << p.x << ", " << p.y << ")\n";
    p.x *= 2.0;
    p.y *= 2.0;
    std::cout << "Rescaled (" << p.x << ", " << p.y << ")\n";
}

static void testAreaOfCircle() {
    Circle c;
    c.radius = 4.0;
    ASSERT_APPROX_EQUAL(c.area(), 16*PI, 0.01);
}

static void testCircumferenceOfCircle() {
    Circle c;
    c.radius = 2.0;
    ASSERT_APPROX_EQUAL(c.circumference(), 4*PI, 0.01);
}

static void testPolarToCartesian() {
    PolarPoint p;
    p.r = 2.0;
    p.theta = PI/2;
    CartesianPoint c = polarToCartesian(p);
    ASSERT_APPROX_EQUAL(c.x, 0.0, 0.001);
    ASSERT_APPROX_EQUAL(c.y, 2.0, 0.001);
}

static void testCartesianToPolar() {
    std::vector<double> angles;
    angles.push_back(0.0);
    angles.push_back(PI/4);
    angles.push_back(PI/2);
    angles.push_back(3*PI/4);
    angles.push_back(PI);
    angles.push_back(-PI/4);
    angles.push_back(-PI/2);
    angles.push_back(-3*PI/4);

    int nAngles = angles.size();
    for (int i=0; i<nAngles; i++) {
        PolarPoint p;
        p.r = 2.0;
        p.theta = angles[i];
        CartesianPoint c = polarToCartesian(p);
        PolarPoint p2;
        p2 = cartesianToPolar(c);
        ASSERT_APPROX_EQUAL(p.r, p2.r, 0.001);
        ASSERT_APPROX_EQUAL(p.theta, p.theta, 0.001);
    }
}


void testGeometry() {
    TEST(testUsage);
    TEST(testAreaOfCircle);
    TEST(testCircumferenceOfCircle);
    TEST(testPolarToCartesian);
    TEST(testCartesianToPolar);
}