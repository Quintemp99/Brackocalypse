cmake_minimum_required(VERSION 3.25.1)
project(Brackocalypse)

set(CMAKE_CXX_STANDARD 17)

add_executable(Brackocalypse main.cpp)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ../Brack-Engine/cmake-build-debug)
find_library(Brack_Engine_LIBRARY Brack_Engine)

if (NOT Brack_Engine_LIBRARY)
    message(FATAL_ERROR "Brack_Engine library not found")
endif ()

if (WIN32 OR WIN64)
    file(GLOB DLL_FILES ../Brack-Engine/cmake-build-debug/*.dll)
    file(COPY ${DLL_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif ()

target_link_libraries(Brackocalypse PRIVATE ${Brack_Engine_LIBRARY})
target_include_directories(Brackocalypse PRIVATE ../Brack-Engine/outfacingInterfaces)