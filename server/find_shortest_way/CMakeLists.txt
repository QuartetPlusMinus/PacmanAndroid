cmake_minimum_required(VERSION 3.10)
project(find_shortest_way)

set(CMAKE_CXX_STANDARD 11)

add_executable(find_shortest_way main.cpp SetGraph.cpp SetGraph.h VirtGraph.h)