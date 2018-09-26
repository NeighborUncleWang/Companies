cmake_minimum_required(VERSION 3.3)
project(kNeareastPointsToOriginalPoint)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(kNeareastPointsToOriginalPoint ${SOURCE_FILES})