cmake_minimum_required(VERSION 3.17)
project(ascii_art)

set(CMAKE_CXX_STANDARD 14)

add_executable(ascii_art
        cmake-build-debug/ascii_art.txt
        ascii_art.cpp)
