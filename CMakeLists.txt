cmake_minimum_required(VERSION 3.27)
project(lod-client-test-1)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(Boost 1.65.0 REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(lod-client-test-1 main.cpp)
target_link_libraries(lod-client-test-1 ${SDL2_LIBRARIES})