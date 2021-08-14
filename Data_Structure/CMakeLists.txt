cmake_minimum_required(VERSION 3.6)
project(Data_Structure)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

set(SOURCE_FILES main.cpp Tree/BST/BST.cpp Linked_List/Singly/singly.cpp Test/test_bst.cpp Test/test_singly.cpp)
add_executable(Data_Structure ${SOURCE_FILES})
target_link_libraries(Data_Structure gtest gtest_main)
