cmake_minimum_required(VERSION 3.20)
project(sequence)

set(CMAKE_CXX_STANDARD 14)

add_executable(sequence main.cpp num_sequence.cpp num_sequence.h Fibonacci.cpp Fibonacci.h Pell.cpp Pell.h)
