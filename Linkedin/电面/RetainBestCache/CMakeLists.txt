cmake_minimum_required(VERSION 3.3)
project(RetainBestCache)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(RetainBestCache ${SOURCE_FILES})