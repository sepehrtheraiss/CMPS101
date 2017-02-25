cmake_minimum_required(VERSION 3.6)
project(pa4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES GraphTest.c List.h List.c Graph.c Graph.h)
add_executable(pa4 ${SOURCE_FILES})