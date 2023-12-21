#include "FirstLevel.hpp"
#include <Components/AnimationComponent.hpp>
#include <Components/GraphComponent.hpp>
#include <Components/RectangleComponent.hpp>
#include "BrackEngine.hpp"
#include "../../Brack-Engine/src/ConfigSingleton.hpp"
#include "../../Helpers/RogueLikeSheetMap.hpp"
#include "../../Player.hpp"
#include "../../../Scripts/FollowGameObject.hpp"
#include "../../LevelBuilder.hpp"
#include "Components/SoundTrackComponent.hpp"
#include "../../Bullet.hpp"
#include "../../../Scripts/EnemySpawn.hpp"
#include "../../PoolCreator.hpp"
#include "../../Enemy.hpp"
#include "../../PauseMenu.hpp"
#include "EngineManagers/ReplayManager.hpp"
#include "../../PauseManager.hpp"
#include "../../ProgressBar.hpp"
#include "../../PlayerHealthBar.hpp"
#include "../../Components/WanderSoundComponent.hpp"
#include "../../../Scripts/SpawnInBeers.hpp"
#include "../../EnemyKillHud.hpp"

void FirstLevel::build() {
    Scene::build();
    ReplayManager::getInstance().startRecording(10000, 100);

    auto camera = getAllCameras()[0];
    camera->addComponent(VelocityComponent());
    camera->SetBackgroundColor(Color(99, 197, 207, 255));
    camera->addBehaviourScript(FollowGameObject("Player"));
    auto backgroundSound = std::make_unique<SoundTrackComponent>("Sounds/background.mp3");
    backgroundSound->volume = 0.02;
    backgroundSound->startPlaying = true;
    camera->addComponent(std::move(backgroundSound));

    std::vector<std::vector<std::string>> objectMap{};
    std::vector<std::vector<std::string>> tileMap{};
    std::vector<std::string> collisionMap{};

    collisionMap.emplace_back("...............................................");
    collisionMap.emplace_back("...............................................");
    collisionMap.emplace_back("...............................................");
    collisionMap.emplace_back("...............................................");
    collisionMap.emplace_back("...............................................");
    collisionMap.emplace_back("......xxxxxxxxxxxxxxxx.........................");
    collisionMap.emplace_back(".....x,,B,,,,,,,,,,,,Bx........................");
    collisionMap.emplace_back(".....x,,,,,,E,,,,,,,,,x........................");
    collisionMap.emplace_back(".....x,,,x,,,,,,,,x,,,x........................");
    collisionMap.emplace_back(".....x,,,,,,x,,,,,,,,,x........................");
    collisionMap.emplace_back(".....x,,,,,,,,,,,,,,,,x........................");
    collisionMap.emplace_back(".....x,x,,x,,,,,x,,B,,x........................");
    collisionMap.emplace_back(".....x,B,,,,,,,,,,,,,,x........................");
    collisionMap.emplace_back("....x,,,,,,,x,x,,,,x,,x.........xxxxxxxxxx.....");
    collisionMap.emplace_back(".....x,,,,xx,,,,x,,,,,x........x,B,,,,,,,,x....");
    collisionMap.emplace_back(".....x,,,,,x,,,,,,,,,,xxxxxxxxxx,,,,,,,,,,x....");
    collisionMap.emplace_back(".....x,,,,,,,,,,,,x,,,,,,,,,,,,,,,,,,,,E,,x....");
    collisionMap.emplace_back(".....x,,x,,B,,,x,,,,,,xxxxxxxxxx,,,,,,,,,,x....");
    collisionMap.emplace_back(".....x,,,,,,,,,,,,,,,,x........x,,,,,,,,,,x....");
    collisionMap.emplace_back(".....x,,,,,x,,,,,,,,,,x........x,,,,,,,,,,x....");
    collisionMap.emplace_back(".....x,,,,,,,,,,,,E,,,x........x,,,E,,,B,,x....");
    collisionMap.emplace_back(".....xB,E,,,,,,,B,,,,,x........x,,,,,,,,,,x....");
    collisionMap.emplace_back("......xxxxxxxxxxxxxxxx..........xxxxxxxxxx.....");
    collisionMap.emplace_back("...............................................");
    collisionMap.emplace_back("...............................................");
    collisionMap.emplace_back("...............................................");

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
    tileMap[1].emplace_back(".........K........K............................");
    tileMap[1].emplace_back("............K..................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back(".......K..K.....K..............................");
    tileMap[1].emplace_back(".....J.........................................");
    tileMap[1].emplace_back(".....a......D.R....K...........................");
    tileMap[1].emplace_back("..........ij....K..............................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("..................K...bbbbbbbbbb...............");
    tileMap[1].emplace_back("........K......K...............................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...........K...................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");
    tileMap[1].emplace_back("...............................................");

    tileMap.emplace_back();
    tileMap[2].emplace_back("...............................................");
    tileMap[2].emplace_back("...............................................");
    tileMap[2].emplace_back("...............................................");
    tileMap[2].emplace_back("...............................................");
    tileMap[2].emplace_back("...............................................");
    tileMap[2].emplace_back("...............................................");
    tileMap[2].emplace_back(".........O........O............................");
    tileMap[2].emplace_back("............O..................................");
    tileMap[2].emplace_back("...............................................");
    tileMap[2].emplace_back(".......O..O.....O..............................");
    tileMap[2].emplace_back("...............................................");
    tileMap[2].emplace_back("...................O...........................");
    tileMap[2].emplace_back("..........gh....O..............................");
    tileMap[2].emplace_back("...............................................");
    tileMap[2].emplace_back("..................O............................");
    tileMap[2].emplace_back("........O......O...............................");
    tileMap[2].emplace_back("...............................................");
    tileMap[2].emplace_back("...........O...................................");
    tileMap[2].emplace_back("...............................................");
    tileMap[2].emplace_back("...............................................");
    tileMap[2].emplace_back("...............................................");
    tileMap[2].emplace_back("...............................................");
    tileMap[2].emplace_back("...............................................");
    tileMap[2].emplace_back("...............................................");

    objectMap.emplace_back();
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............l...............................");
    objectMap[0].emplace_back("....H..........................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...........I...................................");
    objectMap[0].emplace_back("...................d.l.........................");
    objectMap[0].emplace_back("........l.............................l........");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");
    objectMap[0].emplace_back("...............................................");

    auto levelBuilder = LevelBuilder(objectMap, tileMap, collisionMap);

    levelBuilder.buildLevel(MapType::Outdoor);

    auto bulletPool = std::make_unique<PoolCreator<Bullet>>(1, 30);
    auto enemyPool = std::make_unique<PoolCreator<Enemy>>(1, 30, 3);
    auto beerPool = std::make_unique<PoolCreator<Beer>>(1, 6);
    beerPool->addBehaviourScript(SpawnInBeers(5000));

    auto parent = std::make_unique<GameObject>();
    parent->setName("GameParent");

    auto zombieWanderSound = std::make_unique<WanderSoundComponent>("Sounds/zombie-sound.mp3");
    zombieWanderSound->volume = 0.01;

    auto enemySpawner = std::make_unique<GameObject>();
    enemySpawner->addBehaviourScript(EnemySpawn(4000));
    enemySpawner->addComponent(std::move(zombieWanderSound));
    parent->addChild(std::move(enemySpawner));

    parent->addChild(std::move(beerPool));
    parent->addChild(std::move(bulletPool));
    parent->addChild(std::move(enemyPool));

    auto progressBar = std::make_unique<ProgressBar>(Vector2(500, 30));
    parent->addChild(std::move(progressBar));
    
    auto enemyKillHud = std::make_unique<EnemyKillHud>();
    parent->addChild(std::move(enemyKillHud));

    for (auto &go: levelBuilder.gameObjects) {
        parent->addChild(std::move(go));
    }

    auto spawnObject = parent->getChildGameObjectByName("PlayerSpawn");
    if (spawnObject.has_value()) {
        auto player = std::make_unique<Player>(spawnObject.value());
        parent->addChild(std::move(player));
    }

    parent->addChild(std::make_unique<PlayerHealthBar>());

    this->addGameObject(std::move(parent));

    auto pause = std::make_unique<PauseMenu>();
    this->addGameObject(std::move(pause));

    auto pauseHandler = std::make_unique<PauseManager>();
    this->addGameObject(std::move(pauseHandler));
}