//
// Created by Olaf van den Berg on 20-12-2023.
//

#include "secondLevel.hpp"
#include <Components/AnimationComponent.hpp>
#include <Components/GraphComponent.hpp>
#include <Components/RectangleComponent.hpp>
#include "BrackEngine.hpp"
#include "../../Brack-Engine/src/ConfigSingleton.hpp"
#include "../Helpers/RogueLikeSheetMap.hpp"
#include "../Player.hpp"
#include "../../Scripts/FollowGameObject.hpp"
#include "../LevelBuilder.hpp"
#include "Components/SoundTrackComponent.hpp"
#include "../Bullet.hpp"
#include "../../Scripts/EnemySpawn.hpp"
#include "../PoolCreator.hpp"
#include "../Enemy.hpp"
#include "../PauseMenu.hpp"
#include "EngineManagers/ReplayManager.hpp"
#include "../PauseManager.hpp"
#include "../ProgressBar.hpp"
#include "../BeerPool.hpp"
#include "../PlayerHealthBar.hpp"
#include "../Components/WanderSoundComponent.hpp"

void SecondLevel::build() {
    Scene::build();
    ReplayManager::getInstance().startRecording(10000, 100);

    auto camera = getAllCameras()[0];
    camera->addComponent(VelocityComponent());
    camera->SetBackgroundColor(Color(0, 0, 0, 0));
    camera->addBehaviourScript(FollowGameObject("Player"));
    auto backgroundSound = std::make_unique<SoundTrackComponent>("Sounds/background.mp3");
    backgroundSound->volume = 0.02;
    backgroundSound->startPlaying = true;
    camera->addComponent(std::move(backgroundSound));

    std::vector<std::vector<std::string>> objectMap{};
    std::vector<std::vector<std::string>> tileMap{};
    std::vector<std::string> collisionMap{};

    collisionMap.emplace_back("..............................................");
    collisionMap.emplace_back("..............................................");
    collisionMap.emplace_back("..............................................");
    collisionMap.emplace_back("..............................................");
    collisionMap.emplace_back("..............................................");
    collisionMap.emplace_back("......xxxxxxxxxxxxxxxx........xxxxxxxx........");
    collisionMap.emplace_back(".....x,,,,,,,,,,,,,,,,x......x,xxxxxx,x.......");
    collisionMap.emplace_back(".....x,,,,,,,,,,,,,,,,x......x,,,,,,,,x.......");
    collisionMap.emplace_back(".....x,,,,,,,,,,,,,,,,xxxxxxxx,,,,,,,,x.......");
    collisionMap.emplace_back(".....x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x.......");
    collisionMap.emplace_back(".....x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x.......");
    collisionMap.emplace_back(".....x,,,,,,,,,,,,,,,,xxxxxxxx,,,,,,,,x.......");
    collisionMap.emplace_back(".....x,,,,,,,,,,,,,,,,x......x,,,,,,,,x.......");
    collisionMap.emplace_back(".....x,,,,,,,,,,,,,,,,x......x,,,,,,,,x.......");
    collisionMap.emplace_back("......xxxxxxx,,xxxxxxx........xxxxxxxx........");
    collisionMap.emplace_back("............x,,x..............................");
    collisionMap.emplace_back("............x,,x..............................");
    collisionMap.emplace_back("............x,,x..............................");
    collisionMap.emplace_back("............x,,x..............................");
    collisionMap.emplace_back("........xxxxx,,xxxxxxx........................");
    collisionMap.emplace_back(".......x,,,,,,,,,x,,,,x.........xxxxxxxxx.....");
    collisionMap.emplace_back(".......x,,,,,,,,,,,,,,x........x,,,,,,,,,x....");
    collisionMap.emplace_back(".......xx,,,,,,,,,,,,,xxxxxxxxxx,,,,,,,,,x....");
    collisionMap.emplace_back(".......x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x....");
    collisionMap.emplace_back(".......x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x....");
    collisionMap.emplace_back(".......x,,,,,,,,,,,,,,xxxxxxxxxx,,,,,,,,,x....");
    collisionMap.emplace_back(".......x,,,,,,,,,,,,,,x........x,,,xxx,,,x....");
    collisionMap.emplace_back(".......x,,,,,,,,,,,,,,x........x,,,xxx,,,x....");
    collisionMap.emplace_back("........xxxxxxxxxxxxxx.........x,,,,,,,,,x....");
    collisionMap.emplace_back("...............................x,,,,,,,,,x....");
    collisionMap.emplace_back("................................xxxxxxxxx.....");
    collisionMap.emplace_back("..............................................");
    collisionMap.emplace_back("..............................................");
    collisionMap.emplace_back("..............................................");

    tileMap.emplace_back();
    tileMap[0].emplace_back("..............................................");
    tileMap[0].emplace_back("........lmmmn.................................");
    tileMap[0].emplace_back("........ostuo.................................");
    tileMap[0].emplace_back("........ovqwo.................................");
    tileMap[0].emplace_back("........ozyxo.................................");
    tileMap[0].emplace_back(".....lmm2mmm2mmmmmmmmmn......lmmmmmmmmn.......");
    tileMap[0].emplace_back(".....osttttttttttttttuo......ovttttttwo.......");
    tileMap[0].emplace_back(".....ovqqqqqqqqqqqqqqwo......ovqqqqqqwo.......");
    tileMap[0].emplace_back(".....ovqqqqqqqqqqqqqqwpmmmmmmrvqqqqqqwo.......");
    tileMap[0].emplace_back(".....ovqqqqqqqqqqqqqqqttttttttqqqqqqqwo.......");
    tileMap[0].emplace_back(".....ovqqqqqqqqqqqqqqqyyyyyyyyqqqqqqqwo.......");
    tileMap[0].emplace_back(".....ovqqqqqqqqqqqqqqwlmmmmmmnvqqqqqqwo.......");
    tileMap[0].emplace_back(".....ovqqqqqqqqqqqqqqwo......ovqqqqqqwo.......");
    tileMap[0].emplace_back(".....ozyyyyyyqqyyyyyyxo......ovyyyyyyxo.......");
    tileMap[0].emplace_back(".....pmmmmmmnvwlmmmmmmr......pmmmmmmmmr.......");
    tileMap[0].emplace_back("............ovwo..............................");
    tileMap[0].emplace_back("............ovwo..............................");
    tileMap[0].emplace_back("............ovwo..............................");
    tileMap[0].emplace_back("............ovwo..............................");
    tileMap[0].emplace_back(".......lmmmmrvwpmmmmmmn.......................");
    tileMap[0].emplace_back(".......osttttqqttttttuo........lmmmmmmmmmn....");
    tileMap[0].emplace_back(".......ovqqqqqqqqqqqqwo........ostttttttuo....");
    tileMap[0].emplace_back(".......ovqqqqqqqqqqqqwpmmmmmmmmrvqqqqqqqwo....");
    tileMap[0].emplace_back(".......ovqqqqqqqqqqqqqttttttttttqqqqqqqqwo....");
    tileMap[0].emplace_back(".......ovqqqqqqqqqqqqqyyyyyyyyyyqqqqqqqqwo....");
    tileMap[0].emplace_back(".......ovqqqqqqqqqqqqwlmmmmmmmmnvqqqqqqqwo....");
    tileMap[0].emplace_back(".......ovqqqqqqqqqqqqwo........ovqqqqqqqwo....");
    tileMap[0].emplace_back(".......ozyyyyyyyyyyyyxo........ovqqqqqqqwo....");
    tileMap[0].emplace_back(".......pmmmmmmmmmmmmmmr........ovqqqqqqqwo....");
    tileMap[0].emplace_back("...............................ozyyyyyyyxo....");
    tileMap[0].emplace_back("...............................pmmmmmmmmmr....");
    tileMap[0].emplace_back("..............................................");
    tileMap[0].emplace_back("..............................................");

    tileMap.emplace_back();
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back(".........$.#..................................");
    tileMap[1].emplace_back("...........@..................................");
    tileMap[1].emplace_back(".........@....................................");
    tileMap[1].emplace_back("..........1.........................*.........");
    tileMap[1].emplace_back("...............................^%&^^^.........");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..........)...................................");
    tileMap[1].emplace_back("................-.................3445........");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("........(.....................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("...................................666........");
    tileMap[1].emplace_back("...................................777........");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");

    tileMap.emplace_back();
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("................_.............................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("...................................809........");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");

    tileMap.emplace_back();
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");
    tileMap[3].emplace_back("..............................................");


    objectMap.emplace_back();
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..................d...........................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");

    auto levelBuilder = LevelBuilder(objectMap, tileMap, collisionMap);

    levelBuilder.buildLevel();

    auto bulletPool = std::make_unique<PoolCreator<Bullet>>(1, 30);
    auto enemyPool = std::make_unique<PoolCreator<Enemy>>(1, 30);

    auto parent = std::make_unique<GameObject>();
    parent->setName("GameParent");

    auto zombieWanderSound = std::make_unique<WanderSoundComponent>("Sounds/zombie-sound.mp3");
    zombieWanderSound->volume = 0.01;

//    auto enemySpawner = std::make_unique<GameObject>();
//    enemySpawner->addBehaviourScript(EnemySpawn(4000));
//    enemySpawner->addComponent(std::move(zombieWanderSound));
//    parent->addChild(std::move(enemySpawner));

    auto beerPool = std::make_unique<BeerPool>(6);
    parent->addChild(std::move(beerPool));
    parent->addChild(std::move(bulletPool));
    parent->addChild(std::move(enemyPool));

    auto progressBar = std::make_unique<ProgressBar>();
    parent->addChild(std::move(progressBar));


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
