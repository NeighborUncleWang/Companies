cmake_minimum_required(VERSION 3.3)
project(LCA_of_Nary_Tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(LCA_of_Nary_Tree ${SOURCE_FILES})