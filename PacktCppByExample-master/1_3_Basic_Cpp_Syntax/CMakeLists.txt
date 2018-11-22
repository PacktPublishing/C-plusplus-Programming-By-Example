cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(BasicSyntax)

set(project_source
    src/main.cpp)

add_executable(${PROJECT_NAME}
    ${project_source})
    