cmake_minimum_required(VERSION 3.19.8)
project(MiniJava)

add_subdirectory(Grammar)
add_subdirectory(Visitors)

add_library(Driver CompilerDriver.cpp ScannerImpl.cpp Location.cpp)
add_dependencies(Driver Grammar Visitors)
target_link_libraries(Driver Grammar Visitors)
