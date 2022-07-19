cmake_minimum_required(VERSION 3.21)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp main.cpp details.cpp details.h graph.cpp graph.h tree.h tree.cpp dp.cpp dp.h backtracking.cpp backtracking.h)
