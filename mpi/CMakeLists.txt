cmake_minimum_required(VERSION 3.3)

project(qsmpi)

#find_package(MPI REQUIRED)
#find_package(Threads REQUIRED)

set(SOURCE_FILES main.cpp root.cpp root.h job.cpp job.h worker.cpp worker.h)

include_directories(..)

# add_definitions(-DMPICH_IGNORE_CXX_SEEK)
add_definitions(-DENABLE_TRACE)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -pthread" )

add_executable(qs ${SOURCE_FILES})
target_link_libraries(quicksort_lib)
