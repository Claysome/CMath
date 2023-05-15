#include "CallOption.h"
#include "matlib.h"

double CallOption::payoff(double stockAtMaturity) const {
    return std::max(stockAtMaturity - strike, 0.0);
}

double CallOption::price(const BlackScholesModel& bsm) const {
    double S = bsm.stockPrice;
    double K = strike;
    double T = maturity - bsm.date;
    double r = bsm.riskFreeRate;
    double sigma = bsm.volatility;

    double d1 = (log(S / K) + (r + sigma * sigma * 0.5) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);

    return S * normcdf(d1) - K * exp(-r * T) * normcdf(d2);
}


//////////////////////////
//
//  Test the call option class
//  
//
//////////////////////////

static void testCallOptionPrice() {
    CallOption callOption;
    callOption.strike = 105.0;
    callOption.maturity = 2.0;

    BlackScholesModel bsm;
    bsm.date = 1.0;
    bsm.stockPrice = 100.0;
    bsm.volatility = 0.1;
    bsm.riskFreeRate = 0.05;

    double price = callOption.price(bsm);
    ASSERT_APPROX_EQUAL(price, 4.046, 0.01);
}

void testCallOption() {
    TEST(testCallOptionPrice);
}