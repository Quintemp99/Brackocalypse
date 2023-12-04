#include <Components/AIComponent.hpp>
#include <Components/AnimationComponent.hpp>
#include <Components/SoundTrackComponent.hpp>
#include <Objects/Button.hpp>
#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"
#include "../Brack-Engine/src/ConfigSingleton.hpp"
#include "Src/SaveLoad.hpp"
#include "Src/Helpers/RogueLikeSheetMap.hpp"
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
    camera.addComponent(VelocityComponent());
    camera.SetBackgroundColor(Color(0, 255, 0, 255));
    camera.setTag("mainCamera");
    camera.addComponent(FollowGameObject("Player"));
    auto backgroundSound = std::make_unique<SoundTrackComponent>("Sounds/background.mp3");
    backgroundSound->volume = 0.02;
    backgroundSound->startPlaying = true;
    camera.addComponent(std::move(backgroundSound));
    auto scene = Scene(std::move(camera));

    std::vector<std::vector<std::string>> map{};
    map.emplace_back();
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWW...................");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWW...................");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWW...................");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWW...................");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWW...................");
    map[0].emplace_back("WWWWWLQQQQQQQQQQQQQQQQNWWWWW...................");
    map[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWW...................");
    map[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWW...................");
    map[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWLQQQQQQQQQQNWWWW");
    map[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPWWWW");
    map[0].emplace_back("WWWWWVYYYYYYYYYYYYYYYYCWWWWWWWWVYYYYYYYYYYCWWWW");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    map[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");

    map.emplace_back();
    map[1].emplace_back("...............................................");
    map[1].emplace_back("...............................................");
    map[1].emplace_back("...............................................");
    map[1].emplace_back("...............................................");
    map[1].emplace_back("...............................................");
    map[1].emplace_back("....e..........................................");
    map[1].emplace_back("...F.....O........O............................");
    map[1].emplace_back("..F.F....K..O.....K............................");
    map[1].emplace_back("...e........K..................................");
    map[1].emplace_back(".......O..O.....O..............................");
    map[1].emplace_back("...F...K..K.....K..............................");
    map[1].emplace_back("..e.HJ.............O...........................");
    map[1].emplace_back(".....a....ghD.R.O..K...........................");
    map[1].emplace_back("...F......ij....K........F..F..................");
    map[1].emplace_back("..e........I......O.....e....e.................");
    map[1].emplace_back("....e...O...d..O..K.......F...F................");
    map[1].emplace_back("...F....K......K......bbbbbbbbbb...............");
    map[1].emplace_back("..F........O...........e..e..F.................");
    map[1].emplace_back("...........K.............F..e..................");
    map[1].emplace_back("........................e......................");
    map[1].emplace_back("...............................................");
    map[1].emplace_back("...............................................");
    map[1].emplace_back("...............................................");
    map[1].emplace_back("...............................................");

    auto levelBuilder = LevelBuilder(map);

    levelBuilder.buildLevel();

    for (auto &go: levelBuilder.gameObjects) {
        scene.AddGameObject(std::move(go));
    }

    auto player = std::make_unique<Player>(scene.GetGameObjectByName("PlayerSpawn"));
    scene.AddGameObject(std::move(player));

    SceneManager::getInstance().setActiveScene(scene);

    brackEngine.Run();
    return 0;
}