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
    tileMap[0].emplace_back("WWWWWWWFWWWWWWWWWWWWWWWeWWWW...................");
    tileMap[0].emplace_back("WFWWWWWWWWWWWWWWWWFWWWWWWWWW...................");
    tileMap[0].emplace_back("WWWWWFWWWWWeWWWWWWWWWWWFWWWW...................");
    tileMap[0].emplace_back("WWeeWWWWWWWWWWWWWFWWWWWWWWFW...................");
    tileMap[0].emplace_back("WWWWFWWWWFWWeWWeWWWWWFWWWWWW...................");
    tileMap[0].emplace_back("WWFWWLQQQQQQQQQQQQQQQQNWWeWW...................");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWFWWW...................");
    tileMap[0].emplace_back("WeWWFUGGGGGGGGGGGGGGGGPWWWWW...................");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWeWWWWWWWWWWFWWWWWWWWWWW");
    tileMap[0].emplace_back("WWFWWUGGGGGGGGGGGGGGGGPWWWWFWWWWFWWWWWWFWWWWWWW");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWWWWWWWeeWWWWWFWW");
    tileMap[0].emplace_back("eWWWWUGGGGGGGGGGGGGGGGPWWFWWWWWWWWFWWWWWWeWWWWW");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWeWWWWWWWFWWWeWFWWW");
    tileMap[0].emplace_back("WWWFWUGGGGGGGGGGGGGGGGPWWWWWWWWLQQQQQQQQQQNWWWW");
    tileMap[0].emplace_back("WWWeWUGGGGGGGGGGGGGGGGPWWWWWWFWUGGGGGGGGGGPWWWe");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWFWWWWUGGGGGGGGGGPWWWW");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPFWWW");
    tileMap[0].emplace_back("WFWWWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPeWWW");
    tileMap[0].emplace_back("WWeWWUGGGGGGGGGGGGGGGGPWWeWWWWWUGGGGGGGGGGPWWWW");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWFWWWWeWUGGGGGGGGGGPWWFW");
    tileMap[0].emplace_back("WWWFWUGGGGGGGGGGGGGGGGPWWWWWWWWUGGGGGGGGGGPWWWW");
    tileMap[0].emplace_back("WWWWWUGGGGGGGGGGGGGGGGPWWeWWWFWUGGGGGGGGGGPWWWW");
    tileMap[0].emplace_back("WWWWWVYYYYYYYYYYYYYYYYCWWWWWWWWVYYYYYYYYYYCWWeW");
    tileMap[0].emplace_back("WWWWWWFWWWWWWWWWeWWWWWWWWWWWWWWWWWWWWWFWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWFWWWWWWWWFWWWWWWWWWWWWWWWWWWWFWWWW");
    tileMap[0].emplace_back("WWWFWWWWWWWWWWWFWWWWWWWWWWWWWWFWWWWWWWWWWWWWWWW");

    tileMap.emplace_back();
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("....HJ.........................................");
    tileMap[1].emplace_back(".....a.........................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back(".....................bbbbbbbbbb...............");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");

    objectMap.emplace_back();
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back(".........O........O............................");
    objectMap[0].emplace_back(".........K..O.....K............................");
    objectMap[0].emplace_back("............K..................................");
    objectMap[0].emplace_back(".......O..O.....O..............................");
    objectMap[0].emplace_back(".......K..K.....K..............................");
    objectMap[0].emplace_back("...................O...........................");
    objectMap[0].emplace_back("..........ghD.R.O..K...........................");
    objectMap[0].emplace_back("..........ij....K..............................");
    objectMap[0].emplace_back("..................O............................");
    objectMap[0].emplace_back("........O......O..K............................");
    objectMap[0].emplace_back("........K......K...............................");
    objectMap[0].emplace_back("...........O...................................");
    objectMap[0].emplace_back("...........K...................................");
    objectMap[0].emplace_back("...............................................");
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