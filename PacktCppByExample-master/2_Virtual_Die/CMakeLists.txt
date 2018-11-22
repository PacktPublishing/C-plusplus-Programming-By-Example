cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(VirtualDie)

set(project_sources
    src/main.cpp)

add_executable(${PROJECT_NAME} ${project_sources})