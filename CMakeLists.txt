cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(HPC_SIMULATOR)

# Find SimGrid
# The SimGrid library is required for this project
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
find_package(SimGrid 3.27 REQUIRED)

include_directories(${SimGrid_INCLUDE_DIR})

add_executable(main src/main.cpp)
target_link_libraries(main ${SimGrid_LIBRARY})

