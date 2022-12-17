cmake_minimum_required(VERSION 3.23)
project(untitled1 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled1 main.c detail.c detail.h details_cmp.c heap_sort.c sort_utilites.c shaker_sort.c)
