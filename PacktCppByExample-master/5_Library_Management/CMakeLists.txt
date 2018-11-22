cmake_minimum_required(VERSION 3.11)

project(BooksLibrary)

set(project_sources
    src/application.cpp
    src/book_library.cpp
    src/book_library_parser.cpp
    src/main.cpp)

set(project_headers
    include/book.h
    include/book_library.h
    include/book_library_parser.h
    include/application.h)

add_executable(${PROJECT_NAME} ${project_sources} ${project_headers})

target_include_directories(${PROJECT_NAME} 
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_definitions(${PROJECT_NAME} PRIVATE DATA_DIRECTORY="${CMAKE_CURRENT_SOURCE_DIR}/data")