cmake_minimum_required(VERSION 3.11.0)
project(ToolBoxCpp VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE "Release")
message(STATUS "cmake build type: " ${CMAKE_BUILD_TYPE})

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)


set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE STRING "project dir")
message(STATUS ${PROJECT_DIR})

add_subdirectory(3rdparty)

# ToolBoxCpp library
include_directories(include/toolbox/utils)

add_subdirectory(src)