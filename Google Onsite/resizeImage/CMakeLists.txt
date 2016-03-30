cmake_minimum_required(VERSION 3.3)
project(resizeImage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(resizeImage ${SOURCE_FILES})