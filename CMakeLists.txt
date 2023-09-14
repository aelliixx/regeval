cmake_minimum_required(VERSION 3.26)
project(Regexp)

set(CMAKE_CXX_STANDARD 20)

add_library(Print src/libs/Println.hpp
        src/libs/Colours.hpp)

set_target_properties(Print PROPERTIES LINKER_LANGUAGE CXX)

add_executable(Regexp src/Regex.h
        src/main.cpp)

target_link_libraries(${PROJECT_NAME} Print)
target_include_directories(${PROJECT_NAME} PRIVATE src)
