cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME Laboratory_4)
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)

add_executable("${PROJECT_NAME}" Lab4.cpp Class_lab4.hpp Class_lab4.cpp)
