cmake_minimum_required(VERSION 3.17)
project(hw_6_new2 C)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -ansi -pedantic-errors -lm")

add_executable(hw_6_new2 BaseData.h Car.c Car.h Client.c Client.h Company.c Company.h Input_checker.c Input_checker.h main.c matam.c matam.h Structures.h Supplier.c Supplier.h System.c System.h)