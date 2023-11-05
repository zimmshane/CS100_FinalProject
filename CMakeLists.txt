cmake_minimum_required(VERSION 2.5)
project(CLI-lock)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fno-inline -Wall -Wextra -Wpedantic -Wconversion -Wcast-align -Wold-style-cast -Wpointer-arith -Wcast-qual -Wunused -Wshadow -Wno-missing-braces")

# add_executable(a ./src/main.cpp) # prod build, make sure to change flags for this build
add_executable(d ./src/test_staging.cpp) # dev build