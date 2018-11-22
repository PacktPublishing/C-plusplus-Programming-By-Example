cmake_minimum_required(VERSION 3.11.0 FATAL_ERROR)

project(ClassesAndStructures)

set(CMAKE_CXX_STANDARD 17)

set(project_sources 
    src/main.cpp)

add_executable(${PROJECT_NAME} ${project_sources})