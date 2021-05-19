cmake_minimum_required(VERSION 3.19.8)
project(MiniJava)

set(CMAKE_CXX_STANDARD 17)
set(MAIN_SOURCE main.cpp)
include_directories(${PROJECT_SOURCE_DIR})
file(MAKE_DIRECTORY include/FlexBisonOutput)
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

BISON_TARGET(
        MiniJavaParser
        src/parser.y
        ${CMAKE_CURRENT_SOURCE_DIR}/include/FlexBisonOutput/parser.cpp
        DEFINES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/include/FlexBisonOutput/parser.hh
)

FLEX_TARGET(
        MiniJavaScanner
        src/Scanner.l
        ${CMAKE_CURRENT_SOURCE_DIR}/include/FlexBisonOutput/Scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MiniJavaScanner MiniJavaParser)

add_library(Generated include/FlexBisonOutput/parser.hh include/FlexBisonOutput/location.hh
        include/FlexBisonOutput/parser.cpp include/FlexBisonOutput/Scanner.cpp)

include_directories(include)
add_subdirectory(src)
add_executable(MiniJavaCompiler main.cpp)
add_dependencies(MiniJavaCompiler Driver Generated)
target_link_libraries(
        MiniJavaCompiler
        ${Boost_PROGRAM_OPTIONS_LIBRARY}
)
target_link_libraries(MiniJavaCompiler Driver Generated)

# Setting Up GTest
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTest_SOURCE_DIR}/include ${GTest_SOURCE_DIR})
add_executable(MiniJavaCompilerTest test/tests.cpp)
add_dependencies(MiniJavaCompilerTest Driver Generated)
target_link_libraries(MiniJavaCompilerTest Driver Generated)
target_link_libraries(MiniJavaCompilerTest gtest gtest_main pthread)
