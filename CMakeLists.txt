cmake_minimum_required(VERSION 3.15)
project(MiniJava)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)
set(CMAKE_CXX_STANDARD 17)

set(
        HEADERS
        CompilerDriver.h
)

BISON_TARGET(
        MiniJavaParser
        parser.y
        ${CMAKE_CURRENT_SOURCE_DIR}/FlexBisonOutput/parser.cpp
        DEFINES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/FlexBisonOutput/parser.hh
)

FLEX_TARGET(
        MiniJavaScanner
        Scanner.l
        ${CMAKE_CURRENT_SOURCE_DIR}/FlexBisonOutput/Scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MiniJavaScanner MiniJavaParser)
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/FlexBisonOutput)

add_executable(
        MiniJavaParser
        main.cpp
        FlexBisonOutput/parser.hh FlexBisonOutput/parser.cpp
        FlexBisonOutput/Scanner.cpp
        CompilerDriver.cpp CompilerDriver.h
        expressions/NumberExpression.cpp
        expressions/MulExpression.cpp
        expressions/AddExpression.cpp
        expressions/SubstractExpression.cpp
        expressions/DivExpression.cpp
        expressions/IdentExpression.cpp
        assignments/Assignment.cpp
        assignments/AssignmentList.cpp
        ProgramTree.cpp ProgramTree.h Scanner.h Location.cpp Location.h ScannerImpl.cpp)


