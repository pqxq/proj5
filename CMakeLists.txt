cmake_minimum_required(VERSION 3.20)
project(proj5 CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

add_executable(proj5
    main.cpp
    task1.cpp
)

target_link_libraries(proj5 PRIVATE Threads::Threads)