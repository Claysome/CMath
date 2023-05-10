#pragma once

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <stdlib.h>
#include <cassert>

/* Is debugging currently enabled */
bool isDebuggEnabled();
/* Enable/Disable debugging */
void setDebugEnabled(bool enabled);

/* Log information statement */
#define INFO(A) {\
    std::cerr << "INFO: " << __FILE__ << ":" << __LINE__ << ": " << A << std::endl;\
}

#define TEST(f) do {\
    std::cerr << "Calling " << #f << "()\n";\
    try {\
        f();\
    } catch (...) {\
        std::cerr <<"\n";\
        std::cerr << "********************" << #f << "() FAILED. ********************\n";\
        std::cerr <<"\n";\
        exit(1);\
    }\
    std::cerr << "" << #f << "() passed.\n";\
    std::cerr <<"\n";\
} while (false)

// on unix, define debug mode to be when _GLIBCXX is set
#ifdef _GLIBCXX_DEBUG
#define DEBUG_MODE 1
#endif

#ifdef DEBUG_MODE
#define DEBUG_MODE 1
#endif

// assertion macros
#ifndef DEBUG_MODE
#define DEBUG_PRINT(A)
#define ASSERT(c) do {} while (0)
#define ASSERT_APPROX_EQUAL(a, b, tol) do {} while (0)

#else
/* Debugging print */
#define DEBUG_PRINT(A) {\
    if (isDebuggEnabled()) {\
        std::cerr << "DEBUG: " << __FILE__ << ":" << __LINE__ << ": " << A << std::endl;\
    }\
}

#define ASSERT(c) do {\
    if (!(c)) {\
        std::stringstream testing_ss_;\
        testing_ss_ << "ASSERTION FAILED: " << __FILE__ << ":" << __LINE__ << ": " << #c;\
        std::cerr << testing_ss_.str();\
        throw std::runtime_error(testing_ss_.str());\
    }\
} while (0)

#define ASSERT_APPROX_EQUAL(x, y, tolerance) do {\
    if (!(fabs(X - Y)) <= tolerance) {\
        std::stringstream testing_ss_;\
        testing_ss_ << "ASSERTION FAILED: \n";\
        testing_ss_ << "Expected: " << X << "\n";\
        testing_ss_ << "Actual: " << Y << "\n";\
        testing_ss_ << __FILE__ << ":" << __LINE__ << ":\n";\
        std::cerr << testing_ss_.str();\
        throw std::runtime_error(testing_ss_.str());\
    }\
} while (0)

#endif

