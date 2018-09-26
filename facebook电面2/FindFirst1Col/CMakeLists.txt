cmake_minimum_required(VERSION 3.3)
project(FindFirst1Col)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(FindFirst1Col ${SOURCE_FILES})