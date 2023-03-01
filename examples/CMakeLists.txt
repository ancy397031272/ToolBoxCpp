cmake_minimum_required(VERSION 3.10)

project(example)

include_directories("/home/rvbust/Videos/tb/toolbox/include")
set(toolbox /home/rvbust/Videos/tb/toolbox/lib/libtoolbox.so)

add_executable(main main.cpp)
target_link_libraries(main ${toolbox})
