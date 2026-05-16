cmake_minimum_required(VERSION 3.14)

project(multimedia LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(multimedia "main.cpp")