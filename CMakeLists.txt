cmake_minimum_required(VERSION 3.13)
project(Labo09)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wconversion -Wextra -pedantic")

set(CMAKE_CXX_STANDARD 11)

add_executable(Labo09 main.cpp read.cpp read.h search.cpp search.h)