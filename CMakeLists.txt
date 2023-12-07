cmake_minimum_required(VERSION 3.0)
project(CLI-lock)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fno-inline -Wall -Wextra -Wpedantic -Wunused-variable -Wconversion -Wcast-align -Wpointer-arith -Wcast-qual -Wunused -Wshadow")

# prod build flags
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -Wall -Wextra -s -Wl,-s,--as-needed")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

# sub-CMakeLists directories
add_subdirectory(./external/googletest)

# header file directories
include_directories(./include ${CMAKE_SOURCE_DIR}/external/cryptopp)

# dev build
add_executable(dev
    ./src/main.cpp

    ./src/FileHandler.cpp
    ./src/InputValidationHandler.cpp
    ./src/LoginHandler.cpp
    ./src/PasswordManager.cpp
    ./src/PasswordQualityHandler.cpp
    ./src/PrintHandler.cpp
    ./src/UserInputHandler.cpp
    ./src/PasswordGenerator.cpp
    ./src/CipherHandler.cpp
)

# unit dev build unit tests
add_executable(dev_tests
    ./tests/Some_Test_Suite.cpp

    ./src/FileHandler.cpp
    ./src/InputValidationHandler.cpp
    ./src/LoginHandler.cpp
    ./src/PasswordManager.cpp
    ./src/PasswordQualityHandler.cpp
    ./src/PrintHandler.cpp
    ./src/UserInputHandler.cpp
    ./src/PasswordGenerator.cpp
    ./src/CipherHandler.cpp
)

# put your personal test files here, DO NOT PUSH YOUR PERSONAL TEST FILES
# add_executable(jeff ./tests/jeff.cpp ./src/Login.cpp ./src/FileHandler.cpp)
# add_executable(aaron ./tests/aaron.cpp ./src/SearchHandler.cpp ./src/PasswordQualityHandler.cpp ./src/PasswordGenerator.cpp ./src/UserConfig.cpp)

target_link_libraries(dev_tests gtest gtest_main)

add_custom_target(build_cryptopp
    COMMAND ${CMAKE_MAKE_PROGRAM} -C ${CMAKE_SOURCE_DIR}/external/cryptopp
    COMMENT "building Crypto++ library..."
)

# custom command for invoking "make clean"
add_custom_target(cleanbuild) # dummy target
add_custom_command(
    TARGET cleanbuild
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR} # CMakeFiles dir
    COMMENT "Removing previous build artifacts."
)

target_link_libraries(dev_tests gtest gtest_main ${CMAKE_SOURCE_DIR}/external/cryptopp/libcryptopp.a)
target_link_libraries(dev ${CMAKE_SOURCE_DIR}/external/cryptopp/libcryptopp.a)


# add_dependencies(dev_tests cleanbuild)
add_dependencies(gtest cleanbuild build_cryptopp)
add_dependencies(dev build_cryptopp)
