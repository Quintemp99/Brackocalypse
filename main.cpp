#include <Components/AIComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include <Components/SoundTrackComponent.hpp>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
#include "../Brack-Engine/src/ConfigSingleton.hpp"
#include "Src/RogueLikeSheetMap.hpp"
#include "Scripts/UserInputMovement.hpp"
#include "Src/Player.hpp"
#include "Scripts/FollowGameObject.hpp"
#include "Src/LevelBuilder.hpp"

int main() {
    Config config = new Config();
    config.windowTitle = "Brackocalypse";
    config.windowSize = Vector2(640, 640);

    BrackEngine brackEngine = BrackEngine(std::move(config));
    auto camera = Camera();
    camera.AddComponent(VelocityComponent());
    camera.SetBackgroundColor(Color(0, 255, 0, 255));
    camera.SetTag("mainCamera");
    camera.AddComponent(FollowGameObject("Player"));
    auto backgroundSound = std::make_unique<SoundTrackComponent>("Sounds/background.mp3");
    backgroundSound->volume = 0.01;
    backgroundSound->startPlaying = true;
    camera.AddComponent(std::move(backgroundSound));
    auto scene = Scene(std::move(camera));

    std::vector<std::vector<std::string>> map{};
    map.emplace_back();
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWLQQQQQQQQQQNWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWVYYYYYYYYYYCWWWW");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWW");

    map.emplace_back();
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("..........J.........");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");
    map[1].emplace_back("....................");

    auto levelBuilder = LevelBuilder(map);

    levelBuilder.buildLevel();

    for (auto& go: levelBuilder.gameObjects) {
        scene.AddGameObject(std::move(go));
    }

    SceneManager::getInstance().setActiveScene(scene);

    brackEngine.Run();
    return 0;
}