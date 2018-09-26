cmake_minimum_required(VERSION 3.3)
project(fib_n_)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(fib_n_ ${SOURCE_FILES})