cmake_minimum_required(VERSION 3.0.0)
project(assigment12 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(assigment12 main2.cpp)
# add_executable(assigment12_test test.cpp arithmetic-syntax-tree.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
