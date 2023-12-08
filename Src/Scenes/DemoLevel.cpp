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
    auto camera = getAllCameras()[0];
    camera->addComponent(VelocityComponent());
    camera->SetBackgroundColor(Color(0, 255, 0, 255));
    camera->addComponent(FollowGameObject("Player"));
    auto backgroundSound = std::make_unique<SoundTrackComponent>("Sounds/background.mp3");
    backgroundSound->volume = 0.02;
    backgroundSound->startPlaying = true;
    camera->addComponent(std::move(backgroundSound));


    std::vector<std::vector<std::string>> objectMap{};
    std::vector<std::vector<std::string>> tileMap{};
    tileMap.emplace_back();
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWW...................");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWW...................");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWW...................");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWW...................");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWW...................");
    tileMap[0].emplace_back("WWWWWLQQQQQQQQQQQQQQQQNWWWWW...................");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWW...................");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWW...................");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWWWWWWWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWWWWWWWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWWWWWWWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWWWWWWWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWWWWWWWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWLQQQQQQQQQQNWWWW");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPWWWW");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPWWWW");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPWWWW");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPWWWW");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPWWWW");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPWWWW");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPWWWW");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPWWWW");
    tileMap[0].emplace_back("WWWWWVYYYYYYYYYYYYYYYYCWWWWWWWWVYYYYYYYYYYCWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");

    objectMap.emplace_back();
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("....e..........................................");
    objectMap[0].emplace_back("...F.....O........O............................");
    objectMap[0].emplace_back("..F.F....K..O.....K............................");
    objectMap[0].emplace_back("...e........K..................................");
    objectMap[0].emplace_back(".......O..O.....O..............................");
    objectMap[0].emplace_back("...F...K..K.....K..............................");
    objectMap[0].emplace_back("..e.HJ.............O...........................");
    objectMap[0].emplace_back(".....a....ghD.R.O..K...........................");
    objectMap[0].emplace_back("...F......ij....K........F..F..................");
    objectMap[0].emplace_back("..e...............O.....e....e.................");
    objectMap[0].emplace_back("....e...O......O..K.......F...F................");
    objectMap[0].emplace_back("...F....K......K......bbbbbbbbbb...............");
    objectMap[0].emplace_back("..F........O...........e..e..F.................");
    objectMap[0].emplace_back("...........K.............F..e..................");
    objectMap[0].emplace_back("........................e......................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");

    objectMap.emplace_back();
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...........I...................................");
    objectMap[1].emplace_back("............d..................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");
    objectMap[1].emplace_back("...............................................");

    auto levelBuilder = LevelBuilder(objectMap, tileMap);

    levelBuilder.buildLevel();
    auto bulletPool = std::make_unique<BulletPool>(1, 30);
    this->addGameObject(std::move(bulletPool));

    for (auto &go: levelBuilder.gameObjects) {
        this->addGameObject(std::move(go));
    }

    auto player = std::make_unique<Player>(this->getGameObjectByName("PlayerSpawn"));
    this->addGameObject(std::move(player));
}