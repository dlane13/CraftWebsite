cmake_minimum_required(VERSION 3.29)
project(CraftWebsite)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CraftWebsite
        Project.cpp
        Project.h
        Knitting_Project.h
        Crochet_Project.h
        Knitting_Project.cpp
        Crochet_Project.cpp
        Yarn.h
        Yarn.cpp)
