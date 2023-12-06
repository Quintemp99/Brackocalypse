#include "DemoLevel.hpp"
#include <Components/AnimationComponent.hpp>
#include "BrackEngine.hpp"
#include "../../Brack-Engine/src/ConfigSingleton.hpp"
#include "../Helpers/RogueLikeSheetMap.hpp"
#include "../Player.hpp"
#include "../../Scripts/FollowGameObject.hpp"
#include "../LevelBuilder.hpp"
#include "Components/SoundTrackComponent.hpp"
#include "../Gun.hpp"
#include "../Bullet.hpp"
#include "../BulletPool.hpp"

DemoLevel::DemoLevel() : Scene() {
    auto camera = Camera();
    camera.addComponent(VelocityComponent());
    camera.SetBackgroundColor(Color(0, 255, 0, 255));
    camera.addComponent(FollowGameObject("Player"));
    auto backgroundSound = std::make_unique<SoundTrackComponent>("Sounds/background.mp3");
    backgroundSound->volume = 0.02;
    backgroundSound->startPlaying = true;
    camera.addComponent(std::move(backgroundSound));
    this->AddCamera(std::move(camera));

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
    auto bulletPool = std::make_unique<BulletPool>(1, 30);
    this->AddGameObject(std::move(bulletPool));

    for (auto &go: levelBuilder.gameObjects) {
        this->AddGameObject(std::move(go));
    }

    auto player = std::make_unique<Player>(this->GetGameObjectByName("PlayerSpawn"));
    this->AddGameObject(std::move(player));
}