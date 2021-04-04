cmake_minimum_required(VERSION 3.16)
project(algorithm)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(LinkedList)
add_executable(algorithm main.cpp LinkedList/ArrayBasedList.h)