cmake_minimum_required(VERSION 3.27)
project(projectCL1)

set(CMAKE_CXX_STANDARD 17)

add_executable(projectCL1 main.c
        function.c
        column.h
        cdataframe.h)
