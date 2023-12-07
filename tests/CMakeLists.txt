cmake_minimum_required(VERSION 2.5)
project(test-stage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -Wall -Wextra -s -Wl,-s,--as-needed")

# include directories
# ./currentDir/../external/cryptopp
include_directories(${CMAKE_SOURCE_DIR}/../external/cryptopp ${CMAKE_SOURCE_DIR}/../include)

add_executable(scrypt_test
   cipher_testing.cpp
   ../src/CipherHandler.cpp
)

# custom target to build cryptopp's Makefile
add_custom_target(build_cryptopp
    COMMAND ${CMAKE_MAKE_PROGRAM} -C ${CMAKE_SOURCE_DIR}/../external/cryptopp
    COMMENT "building Crypto++ library..."
)

# sha_test depend on build_cryptopp
add_dependencies(scrypt_test build_cryptopp)

# link target against library archive
target_link_libraries(scrypt_test ${CMAKE_SOURCE_DIR}/../external/cryptopp/libcryptopp.a)
