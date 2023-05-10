#include <iostream>
#include <cmath>
#include "matlib.h"

double erfcinv(double x) {
    double z = sqrt(-2.0 * log(0.5 * x));
    double c0 = 2.515517;
    double c1 = 0.802853;
    double c2 = 0.010328;
    double d1 = 1.432788;
    double d2 = 0.189269;
    double d3 = 0.001308;
    return z - ((c0 + c1 * z + c2 * z * z) / (1.0 + d1 * z + d2 * z * z + d3 * z * z * z));
}

double normcdf(double x) {
	return 0.5 * erfc(-x * M_SQRT1_2);
}

double norminv(double x) {
	return -M_SQRT2 * erfcinv(2 * x);
}