cmake_minimum_required(VERSION 3.16)
project(CppDataStructuresLearning LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Topic.cmake)

include(CTest)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(COURSE_TOPICS
    01_Foundations 02_Arrays 03_Strings 04_LinkedLists 05_Stacks 06_Queues
    07_Deques 08_HashTables 09_Trees 10_BinarySearchTrees 11_Heaps
    12_PriorityQueues 13_Tries 14_Graphs 15_DisjointSets 16_STL_DataStructures
    17_Advanced_DataStructures 18_Problems)

foreach(topic IN LISTS COURSE_TOPICS)
    add_subdirectory(${topic})
endforeach()