cmake_minimum_required(VERSION 3.22)
project(src)

set(CMAKE_CXX_STANDARD 14)

add_executable(src main.cpp
        City.h
        City.cpp
        MaxHeap.cpp
        MaxHeap.h
        MinHeap.cpp
        MinHeap.h)
