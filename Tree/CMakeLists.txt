cmake_minimum_required(VERSION 3.6)
project(Tree)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

set(SOURCE_FILES main.cpp BST/BST.cpp BST/BST.h test/test_bst.cpp)
add_executable(Tree ${SOURCE_FILES})
target_link_libraries(Tree gtest gtest_main)
