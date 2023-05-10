#pragma once

const double PI = 3.1415926535897932384626433832795;

/*
* Computes the cumulative normal distribution function.
*/
double normcdf(double x);

/*
* Computes the inverse of the cumulative normal distribution function.
*/
double norminv(double x);

/*
* Test function
*/
void testMatlib();