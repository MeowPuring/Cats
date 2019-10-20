cmake_minimum_required(VERSION 3.5)

project(Cats LANGUAGES CXX)

find_package( Threads )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Cats main.cpp cat.cpp cat.h)

target_link_libraries( Cats ${CMAKE_THREAD_LIBS_INIT} )
