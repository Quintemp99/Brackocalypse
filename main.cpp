#include <Components/TileMapComponent.hpp>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
#include "../Brack-Engine/src/ConfigSingleton.hpp"
#include "Src/Helpers/RogueLikeSheetMap.hpp"
#include "Scripts/UserInputMovement.hpp"
#include "Src/Scenes/HomeScene.hpp"
#include "Scripts/FollowGameObject.hpp"
#include "Src/LevelBuilder.hpp"
#include "Scripts/ToggleFPS.hpp"

int main() {
    Config config = new Config();
    config.fpsLimit = 120;
    config.showFPS = true;
    config.windowTitle = "Brackocalypse";
    config.windowSize = Vector2(640, 640);

    BrackEngine brackEngine = BrackEngine(std::move(config));

    auto scene = new HomeScene();
    SceneManager::getInstance().goToNewScene(scene);

    brackEngine.Run();
    return 0;
}