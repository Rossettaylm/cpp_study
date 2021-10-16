cmake_minimum_required(VERSION 3.20)
project(refactor)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(refactor
        Fibonacci.h
        main.cpp
        num_sequence.h)
