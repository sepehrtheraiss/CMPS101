cmake_minimum_required(VERSION 3.6)
project(Pa4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES GraphTest.c List.h List.c Graph.c Graph.h)
add_executable(Pa4 ${SOURCE_FILES})