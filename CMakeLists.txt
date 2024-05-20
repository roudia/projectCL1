cmake_minimum_required(VERSION 3.27)
project(projectCL1)

set(CMAKE_CXX_STANDARD 17)

add_executable(projectCL1 main.c
        cdataframe.c
        column.h
        column.c
        cdataframe.h
        column.c
        column.c)
