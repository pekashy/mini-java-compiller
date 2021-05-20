cmake_minimum_required(VERSION 3.19.8)
project(MiniJava)

add_subdirectory(Grammar)
add_subdirectory(Visitors)
add_subdirectory(SymbolTree)
add_subdirectory(Objects)

add_library(Driver CompilerDriver.cpp ScannerImpl.cpp Location.cpp)

add_dependencies(Objects Grammar)
target_link_libraries(Objects Grammar)

add_dependencies(SymbolTree Objects)
target_link_libraries(SymbolTree Objects)

add_dependencies(Visitors SymbolTree)
target_link_libraries(Visitors SymbolTree)

add_dependencies(Driver Grammar Visitors)
target_link_libraries(Driver Grammar Visitors)
