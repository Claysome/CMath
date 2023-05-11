#include <iostream>
#include <cmath>
#include "matlib.h"
#include "testing.h"

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
    DEBUG_PRINT("normcdf(" << x << ")");
	return 0.5 * erfc(-x * M_SQRT1_2);
}

double norminv(double x) {
    DEBUG_PRINT("norminv(" << x << ")");
	return -M_SQRT2 * erfcinv(2 * x);
}

///////////////////////////////////////////////
//
//   TESTS
//
///////////////////////////////////////////////

// static void testNormCdf() {
//     // test bounds
//     ASSERT(normcdf(0.3)>0);
//     ASSERT(normcdf(0.3)<1);
//     // test extreme values
//     ASSERT_APPROX_EQUAL(normcdf(-1e10), 0, 0.001);
//     ASSERT_APPROX_EQUAL(normcdf(1e10), 1.0, 0.001);
//     // test increasing
//     ASSERT(normcdf(0.3)<normcdf(0.5));
//     // test symmetry
//     ASSERT_APPROX_EQUAL(normcdf(0.3), 1 - normcdf(-0.3), 0.0001);
//     ASSERT_APPROX_EQUAL(normcdf(0.0), 0.5, 0.0001);
//     // test inverse
//     ASSERT_APPROX_EQUAL(normcdf(norminv(0.3)), 0.3, 0.0001);
//     // test well known value
//     ASSERT_APPROX_EQUAL(normcdf(1.96), 0.975, 0.001);
// }

static void testNormCdf() {
    ASSERT_APPROX_EQUAL(normcdf(1.96), 0.975, 0.001);
}

static void testNormInv() {
    ASSERT_APPROX_EQUAL(norminv(0.975), 1.96, 0.01);
}

void testMatlib() {
    // setDebugEnabled(true);
    TEST(testNormCdf);
    // setDebugEnabled(false);
    TEST(testNormInv);
}