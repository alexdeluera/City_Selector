cmake_minimum_required(VERSION 3.30)
project(src)

set(CMAKE_CXX_STANDARD 20)

add_executable(src main.cpp
        City.cpp
        City.h
        Parser.cpp
        Parser.h
        MaxHeap.cpp
        MaxHeap.h
        MinHeap.cpp
        MinHeap.h)
