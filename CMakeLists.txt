cmake_minimum_required(VERSION 2.8.12)

project(FMLib)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


include_directories(include)

# add_executable(testMacro src/main.cpp
#                          src/matlib.cpp
#                          src/testing.cpp)

add_executable(testClasses src/main.cpp
                           src/matlib.cpp
                           src/geometry.cpp
                           src/charts.cpp
                           src/usageExamples.cpp)