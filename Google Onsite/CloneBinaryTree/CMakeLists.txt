cmake_minimum_required(VERSION 3.3)
project(CloneBinaryTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(CloneBinaryTree ${SOURCE_FILES})