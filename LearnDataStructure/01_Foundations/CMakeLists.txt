cmake_minimum_required(VERSION 3.16)
project(Foundations LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(foundations main.cpp Examples.cpp)
target_include_directories(foundations PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

include(CTest)
if(BUILD_TESTING)
    add_executable(foundations_tests tests/Tests.cpp Examples.cpp)
    target_include_directories(foundations_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    add_test(NAME foundations_invariants COMMAND foundations_tests)
endif()