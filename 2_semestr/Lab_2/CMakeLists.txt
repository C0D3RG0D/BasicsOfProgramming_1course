cmake_minimum_required(VERSION 3.15)


set(PROJECT_NAME Laboratory_2)
project("${PROJECT_NAME}")



set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)

add_executable("${PROJECT_NAME}" Lab2.cpp Class_lab2.hpp Class_lab2.cpp)