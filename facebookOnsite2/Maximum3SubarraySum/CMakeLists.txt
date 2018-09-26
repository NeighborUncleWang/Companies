cmake_minimum_required(VERSION 3.3)
project(Maximum3SubarraySum)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Maximum3SubarraySum ${SOURCE_FILES})