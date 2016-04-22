cmake_minimum_required(VERSION 3.3)

project(quicksort_lib)

find_package(Threads REQUIRED)

set(SOURCE_FILES quicksort.cpp quicksort.h)

add_library(quicksort_lib STATIC ${SOURCE_FILES})
