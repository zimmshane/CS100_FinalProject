cmake_minimum_required(VERSION 3.0)
project(CLI-lock)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fno-inline -Wall -Wextra -Wpedantic -Wconversion -Wcast-align -Wold-style-cast -Wpointer-arith -Wcast-qual -Wunused -Wshadow -Wno-missing-braces")

add_dependencies(./src/main.cpp)