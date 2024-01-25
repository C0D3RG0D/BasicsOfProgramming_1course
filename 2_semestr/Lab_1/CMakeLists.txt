cmake_minimum_required(VERSION 3.15)


set(PROJECT_NAME Laboratory_1)
project("${PROJECT_NAME}")



set(CMAKE_CXX_STANDARD 17)			 
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)



add_executable("${PROJECT_NAME}" Lab1.cpp Class_lab1.hpp Class_lab1.cpp)