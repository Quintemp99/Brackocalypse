#include <Components/AIComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include <Components/SoundTrackComponent.hpp>
#include <Objects/Button.hpp>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
#include "../Brack-Engine/src/ConfigSingleton.hpp"
#include "Components/AudioComponent.hpp"
#include "Src/SaveLoad.hpp"
#include "Src/RogueLikeSheetMap.hpp"
#include "Scripts/UserInputMovement.hpp"
#include "Src/Player.hpp"
#include "Scripts/FollowGameObject.hpp"
#include "Src/LevelBuilder.hpp"
#include "Src/Gun.hpp"

int main() {
    Config config = new Config();
    config.windowTitle = "Brackocalypse";
    config.windowSize = Vector2(640, 640);

    BrackEngine brackEngine = BrackEngine(std::move(config));
    auto camera = Camera();
    camera.addComponent(VelocityComponent());
    camera.SetBackgroundColor(Color(0, 255, 0, 255));
    camera.setTag("mainCamera");
    camera.addComponent(FollowGameObject("Player"));
    auto backgroundSound = std::make_unique<SoundTrackComponent>("Sounds/background.mp3");
    backgroundSound->volume = 0.02;
    backgroundSound->startPlaying = true;
    camera.addComponent(std::move(backgroundSound));
    auto scene = Scene(std::move(camera));

    SaveLoad saveLoad = SaveLoad(brackEngine);
    saveLoad.save();
    saveLoad.load();

    auto object = std::make_unique<GameObject>();
    auto audio = AudioComponent();
    object->AddComponent(audio);
  
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

    for (auto &go: levelBuilder.gameObjects) {
        scene.AddGameObject(std::move(go));
    }

    auto gun = std::make_unique<Gun>(1);
    scene.AddGameObject(std::move(gun));

    SceneManager::getInstance().setActiveScene(scene);
    auto player = SceneManager::getInstance().getGameObjectByTag("Player");
    auto gunObject = SceneManager::getInstance().getGameObjectByTag("Gun");
    player.value().addChild(gunObject.value());
    brackEngine.Run();
    return 0;
}