cmake_minimum_required(VERSION 3.25.1)
project(Brackocalypse)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(../Brack-Engine ${CMAKE_CURRENT_BINARY_DIR}/Brack-Engine_build)

add_executable(Brackocalypse main.cpp
        Src/Scripts/UserInputMovement.cpp
        Src/Scripts/UserInputMovement.hpp
        Src/LevelBuilder.cpp
        Src/LevelBuilder.hpp
        Src/Player.cpp
        Src/Player.hpp
        Src/Scripts/FollowGameObject.cpp
        Src/Scripts/FollowGameObject.hpp
        Src/Factory/LevelFactory.cpp
        Src/Factory/LevelFactory.hpp
        Src/RogueLikeMapTiles/RogueLikeMapTile.hpp
        Src/RogueLikeMapTiles/WaterMapTile.hpp
        Src/Scenes/HomeScene.cpp
        Src/Gun.cpp
        Src/Scripts/GunFollowMouse.cpp
        Src/Scripts/GunShooting.cpp
        Src/SaveLoadGame.cpp
        Src/Bullet.cpp
        Src/Scripts/BulletActions.cpp
        Src/SaveLoadGame.cpp
        Src/RogueLikeMapTiles/FireMapTile.hpp
        Src/RogueLikeMapTiles/PlayerSpawnMapTile.hpp
        Src/SaveLoadGame.cpp
        Src/RogueLikeMapTiles/WaterMapTile.hpp
        Src/RogueLikeMapTiles/BoxCollisionMapTile.hpp
        Src/RogueLikeMapTiles/SolidBoxMapTile.hpp
        Src/Scripts/GunFollowMouse.hpp
        Src/Scripts/EnemyFollowPlayer.cpp
        Src/Scripts/EnemyFollowPlayer.hpp
        Src/Enemy.cpp
        Src/Enemy.hpp
        Src/PoolCreator.hpp
        Src/PoolCreator.hpp
        Src/Scripts/EnemySpawn.cpp
        Src/Scripts/EnemySpawn.hpp
        Src/Scripts/EnemySpawn.hpp
        Src/Components/HealthComponent.hpp
        Src/Components/SpawnComponent.hpp
        Src/RogueLikeMapTiles/PlayerSpawnMapTile.hpp
        Src/Scripts/PlayerProgressScript.cpp
        Src/ProgressBar.cpp
        Src/Scripts/SpawnInBeers.cpp
        Src/Scripts/CollectBeers.cpp
        Src/Scripts/GunFollowMouse.hpp
        Src/Scripts/PauseHandler.cpp
        Src/Scripts/PauseHandler.hpp
        Src/PauseMenu.cpp
        Src/PauseMenu.hpp
        Src/PauseManager.cpp
        Src/PauseManager.hpp
        Src/Scripts/TakeDamage.cpp
        Src/Crate.cpp
        Src/Scripts/UpdateHealth.cpp
        Src/Scripts/UpdateHealth.hpp
        Src/PlayerHealthBar.cpp
        Src/PlayerHealthBar.hpp
        Src/Scripts/PlayBoxMovingSound.cpp
        Src/Scripts/EnemyDamage.cpp
        Src/Scripts/EnemyDamage.hpp
        Src/Components/HitSoundComponent.hpp
        Src/Components/WanderSoundComponent.hpp
        Src/Scripts/BopAnimation.cpp
        Src/Scripts/BopAnimation.hpp
        Src/RogueLikeMapTiles/BoatMapTile.hpp
        Src/Scripts/MovementAnimation.cpp
        Src/Scripts/MovementAnimation.hpp
        Src/Scenes/StoryScene.cpp
        Src/Scenes/StoryScene.hpp
        Src/Scenes/IntroductionScene.cpp
        Src/Scenes/IntroductionScene.hpp
        Src/Scripts/WriteTextAnimation.cpp
        Src/Scripts/WriteTextAnimation.hpp
        Src/Scenes/GameOverScene.cpp
        Src/Scenes/GameOverScene.hpp
        Src/Scenes/InterludeOneScene.cpp
        Src/Scenes/InterludeOneScene.hpp
        Src/Scenes/InterludeTwoScene.cpp
        Src/Scenes/InterludeTwoScene.hpp
        Src/Scenes/InterludeThreeScene.cpp
        Src/Scenes/InterludeThreeScene.hpp
        Src/Scenes/EndScene.cpp
        Src/Scenes/EndScene.hpp
        Src/Scenes/LevelManager.cpp
        Src/Scenes/Levels/SecondLevel.cpp
        Src/Scripts/ToggleFPS.hpp
        Src/Scripts/ToggleFPS.cpp
        Src/Scripts/FullScreenHandler.cpp
        Src/Scripts/WifeComplaints.cpp
        Src/Scripts/WifeComplaints.hpp
        Src/Wife.cpp
        Src/Wife.hpp
        Src/Scenes/Levels/BossLevel.cpp
        Src/Scenes/Levels/BossLevel.hpp
        Src/Scenes/Levels/FirstLevel.cpp
        Src/Scenes/Levels/FirstLevel.hpp
        Src/Helpers/MapType.hpp
        Src/Helpers/RogueLikeSheetIndoorType.hpp
        Src/WifeHealthBar.cpp
        Src/WifeHealthBar.hpp
        Src/Scripts/WifeDeath.cpp
        Src/Scripts/WifeDeath.hpp
        Src/Helpers/RogueLikeSheetIndoorType.hpp
        Src/PlayerProgress.cpp
        Src/EnemyKillHud.cpp
        Src/Scripts/FullScreenHandler.cpp
        Src/Scripts/CreditsScroll.cpp
        Src/Scenes/CreditsScene.cpp
)

target_link_libraries(Brackocalypse PRIVATE Brack_Engine)

target_include_directories(Brackocalypse PRIVATE ../Brack-Engine/outfacingInterfaces)

# Copy DLL files if necessary
if (WIN32 OR WIN64)
    # Adjust the path if necessary to the location of the DLL files
    file(GLOB DLL_FILES ${CMAKE_CURRENT_BINARY_DIR}/Brack-Engine_build/*.dll)
    file(COPY ${DLL_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif ()

add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/Assets
        ${CMAKE_BINARY_DIR}/Assets
)

add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_BINARY_DIR}/Resources
        ${CMAKE_BINARY_DIR}/Assets/Resources
)

