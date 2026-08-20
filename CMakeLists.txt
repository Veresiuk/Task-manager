cmake_minimum_required(VERSION 3.10)

project(TaskManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TaskManager
    src/main.cpp
    src/TaskManager.cpp
    src/DateTime.cpp
)

target_include_directories(TaskManager
    PRIVATE
    include
)