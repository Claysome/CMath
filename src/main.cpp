#include <iostream>
#include "matlib.h"

int main() {
    std::cout << "normcdf(1.96) = " << normcdf(1.96) << std::endl;
    std::cout << "norminv(0.975) = " << norminv(0.975) << std::endl;
    return 0;
}
