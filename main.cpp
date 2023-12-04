#include <Components/AIComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include <Objects/Button.hpp>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
#include "../Brack-Engine/src/ConfigSingleton.hpp"
#include "Src/SaveLoad.hpp"
#include "Src/RogueLikeSheetMap.hpp"
#include "Scripts/UserInputMovement.hpp"
#include "Src/Player.hpp"
#include "Scripts/FollowGameObject.hpp"
#include "Src/LevelBuilder.hpp"
#include "Src/Scenes/HomeScene.hpp"

int main() {
    Config config = new Config();
    config.windowTitle = "Brackocalypse";
    config.windowSize = Vector2(640, 640);

    BrackEngine brackEngine = BrackEngine(std::move(config));

    auto scene = HomeScene();
    SceneManager::getInstance().setActiveScene(scene);

    brackEngine.Run();
    return 0;
}