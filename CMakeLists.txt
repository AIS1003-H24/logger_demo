cmake_minimum_required(VERSION 3.29)
project(logger)

set(CMAKE_CXX_STANDARD 20)

add_executable(logger_demo main.cpp)
target_include_directories(logger_demo PUBLIC "${CMAKE_SOURCE_DIR}/include")
