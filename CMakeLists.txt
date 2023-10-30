cmake_minimum_required(VERSION 3.26)
project(Brackocalypse)

set(CMAKE_CXX_STANDARD 17)

add_executable(Brackocalypse main.cpp)

configure_file(../Brack-Engine/cmake-build-debug/libBrack_Engine.dll ./ COPYONLY)

target_link_libraries(Brackocalypse Brack_Engine)

include_directories(../Brack-Engine)

target_link_directories(Brackocalypse PRIVATE ../Brack-Engine/cmake-build-debug)