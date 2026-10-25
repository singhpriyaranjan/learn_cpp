cmake_minimum_required(VERSION 3.16)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    project(CppLearningBasics LANGUAGES CXX)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(01_Basics
    main.cpp
    Variables.cpp
    DataTypes.cpp
    Constants.cpp
    Operators.cpp
    ScopeAndLifetime.cpp
    TypeConversion.cpp
)

target_include_directories(01_Basics PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})