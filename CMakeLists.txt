cmake_minimum_required(VERSION 4.0)
project(laba5_2026)

set(CMAKE_CXX_STANDARD 20)

add_executable(laba5_2026 main.cpp
        task1/utils.cpp
        task1/utils.h
        task2/utils.cpp
        task2/utils.h
        task3/Matrix.cpp
        task3/Matrix.h
        task4/Polynomial.cpp
        task4/Polynomial.h)
