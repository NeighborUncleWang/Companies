cmake_minimum_required(VERSION 3.3)
project(Sum_Average)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Sum_Average ${SOURCE_FILES})