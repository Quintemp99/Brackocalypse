cmake_minimum_required(VERSION 3.25.1)
project(Brackocalypse)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(../Brack-Engine ${CMAKE_CURRENT_BINARY_DIR}/Brack-Engine_build)

add_executable(Brackocalypse main.cpp
        Scripts/UserInputMovement.cpp
        Scripts/UserInputMovement.hpp
        Src/LevelBuilder.cpp
        Src/LevelBuilder.hpp
        Src/Player.cpp
        Src/Player.hpp
        Scripts/FollowGameObject.cpp
        Scripts/FollowGameObject.hpp
        Src/Factory/LevelFactory.cpp
        Src/Factory/LevelFactory.hpp
        Src/RogueLikeMapTiles/RogueLikeMapTile.hpp
        Src/RogueLikeMapTiles/WaterMapTile.hpp
        Scripts/WalkingSound.cpp
        Scripts/WalkingSound.hpp)

target_link_libraries(Brackocalypse PRIVATE Brack_Engine)

target_include_directories(Brackocalypse PRIVATE ../Brack-Engine/outfacingInterfaces)

# Copy DLL files if necessary
if (WIN32 OR WIN64)
    # Adjust the path if necessary to the location of the DLL files
    file(GLOB DLL_FILES ${CMAKE_CURRENT_BINARY_DIR}/Brack-Engine_build/*.dll)
    file(COPY ${DLL_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif ()
