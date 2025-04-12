cmake_minimum_required(VERSION 3.22)
project(City_Selector)

set(CMAKE_CXX_STANDARD 14)
include_directories(src)

add_executable(Main
        City.cpp
        City.h
        main.cpp
)