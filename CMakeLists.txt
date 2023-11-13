cmake_minimum_required(VERSION 2.5)
project(CLI-lock)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fno-inline -Wall -Wextra -Wpedantic -Wconversion -Wcast-align -Wold-style-cast -Wpointer-arith -Wcast-qual -Wunused -Wshadow -Wno-missing-braces")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

add_subdirectory(external/googletest/)

# add_executable(a ./src/main.cpp) # prod build, make sure to change flags for this build
add_executable(dev ./src/main.cpp) # dev build
add_executable(dev_tests ./tests/Some_Test_Suite.cpp)

target_link_libraries(dev_tests gtest gtest_main)