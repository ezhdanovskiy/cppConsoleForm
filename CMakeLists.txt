cmake_minimum_required(VERSION 2.8)
project(cppConsoleForm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

set(SOURCE_FILES
    src/main.cpp
    src/View.cpp
    src/ViewController.cpp
    src/ViewElements.cpp
    src/Symbols.cpp
    src/Model.cpp
    )
add_executable(cppConsoleForm ${SOURCE_FILES})