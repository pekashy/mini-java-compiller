cmake_minimum_required(VERSION 3.15)
project(MiniJava)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)
set(CMAKE_CXX_STANDARD 17)

set(
        HEADERS
        CompilerDriver.h
        ${MiniJava_SOURCE_DIR}/parser.hh
)

BISON_TARGET(
        MiniJavaParser
        parser.y
        ${MiniJava_SOURCE_DIR}/parser.cpp
        DEFINES_FILE ${MiniJava_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
        MiniJavaScanner
        Scanner.l
        ${MiniJava_SOURCE_DIR}/Scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MiniJavaScanner MiniJavaParser)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(
        MiniJavaParser
        main.cpp
        ${BISON_MiniJavaParser_OUTPUTS}
        ${FLEX_MiniJavaScanner_OUTPUTS}
        CompilerDriver.cpp CompilerDriver.h
        ProgramTree.cpp ProgramTree.h )


