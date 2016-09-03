cmake_minimum_required(VERSION 3.6)
project(cppConsoleForm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

set(SOURCE_FILES
    src/main.cpp
    src/View.cpp
    src/KeyController.cpp
    src/ViewElements.cpp
    src/Symbols.cpp
    )
add_executable(cppConsoleForm ${SOURCE_FILES})