//
// Created by qtemp on 21-12-2023.
//

#include "BossLevel.hpp"

#include "Components/SoundTrackComponent.hpp"
#include "EngineManagers/ReplayManager.hpp"
#include "../../../Scripts/FollowGameObject.hpp"
#include "../../LevelBuilder.hpp"
#include "../../Player.hpp"
#include "../../PlayerHealthBar.hpp"
#include "../../Wife.hpp"
#include "../../Bullet.hpp"
#include "../../Enemy.hpp"
#include "../../PoolCreator.hpp"
#include "../../Components/WanderSoundComponent.hpp"
#include "../../../Scripts/EnemySpawn.hpp"
#include "../../PauseMenu.hpp"
#include "../../PauseManager.hpp"
#include "../../ProgressBar.hpp"

void BossLevel::build()
{
    Scene::build();
    ReplayManager::getInstance().startRecording(10000, 100);

    auto camera = getAllCameras()[0];
    camera->addComponent(VelocityComponent());
    camera->SetBackgroundColor(Color(99, 197, 207, 255));
    camera->addBehaviourScript(FollowGameObject("Player"));
    auto backgroundSound = std::make_unique<SoundTrackComponent>("Sounds/Fuck_me.mp3");
    backgroundSound->volume = 0.02;
    backgroundSound->startPlaying = true;
    camera->addComponent(std::move(backgroundSound));

    std::vector<std::vector<std::string>> objectMap{};
    std::vector<std::vector<std::string>> tileMap{};
    std::vector<std::string> collisionMap{};

    collisionMap.emplace_back("..............................................................");
    collisionMap.emplace_back("..............................................................");
    collisionMap.emplace_back("..............................................................");
    collisionMap.emplace_back("..............................................................");
    collisionMap.emplace_back("....................xxxxxxxxxxxxxxxxxxxxxxxx..................");
    collisionMap.emplace_back("...................x,,,,,,,,,,,,,,,,,,,,,,,,x.................");
    collisionMap.emplace_back("..................x,,,,,,,,,,,,,,,,,,,,,,,,,,x................");
    collisionMap.emplace_back(".................x,,,,,,E,,,,,,,,,,,,,,,,,,,,,x...............");
    collisionMap.emplace_back("................x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x..............");
    collisionMap.emplace_back("...............x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x.............");
    collisionMap.emplace_back("..............x,,,,,,,,,,,,,,,,,,,,,,,,,,,,E,,,,,x............");
    collisionMap.emplace_back(".............x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x...........");
    collisionMap.emplace_back(".....xxxxxxxx,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x..........");
    collisionMap.emplace_back("....x,,,,,,,,,,,,,,,,,,,,E,,,,,,,,,,,,,,,,,,,,,,,,,x..........");
    collisionMap.emplace_back("....x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x..........");
    collisionMap.emplace_back("....x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x..........");
    collisionMap.emplace_back("....x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x..........");
    collisionMap.emplace_back("....x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x..........");
    collisionMap.emplace_back(".....xxxxxxxx,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x..........");
    collisionMap.emplace_back(".............x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x...........");
    collisionMap.emplace_back("..............x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x............");
    collisionMap.emplace_back("...............x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x.............");
    collisionMap.emplace_back("................x,,,,,,E,,,,,,,,,,,,,,,,,,,,,,,x..............");
    collisionMap.emplace_back(".................x,,,,,,,,,,,,,,,,,,,,,,,E,,,,x...............");
    collisionMap.emplace_back("..................x,,,,,,,,,,,,,,,,,,,,,,,,,,x................");
    collisionMap.emplace_back("...................x,,,,,,,,,,,,,,,,,,,,,,,,x.................");
    collisionMap.emplace_back("....................xxxxxxxxxxxxxxxxxxxxxxxx..................");
    collisionMap.emplace_back("..............................................................");
    collisionMap.emplace_back("..............................................................");
    collisionMap.emplace_back("..............................................................");
    collisionMap.emplace_back("..............................................................");

    tileMap.emplace_back();
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWxxxxxxxxxxxxxxxxxxxxxxxxWWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWxGGGGGGGGGGGGGGGGGGGGGGGGxWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWxGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWxGGGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWxGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWxGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWxGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWxGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWWW");
    tileMap[0].emplace_back("WWWWWxxxxxxxxGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWW");
    tileMap[0].emplace_back("WWWWxGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWW");
    tileMap[0].emplace_back("WWWWxGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWW");
    tileMap[0].emplace_back("WWWWxGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWW");
    tileMap[0].emplace_back("WWWWxGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWW");
    tileMap[0].emplace_back("WWWWxGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWW");
    tileMap[0].emplace_back("WWWWWxxxxxxxxGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWxGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWxGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWxGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWxGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWxGGGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWxGGGGGGGGGGGGGGGGGGGGGGGGGGxWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWxGGGGGGGGGGGGGGGGGGGGGGGGxWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWxxxxxxxxxxxxxxxxxxxxxxxxWWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");

    tileMap.emplace_back();
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");

    objectMap.emplace_back();
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("......d.................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("........................................................");

    auto levelBuilder = LevelBuilder(objectMap, tileMap, collisionMap);

    levelBuilder.buildLevel();

    auto enemyPool = std::make_unique<PoolCreator<Enemy>>(1, 30, 5, 20);
    auto bulletPool = std::make_unique<PoolCreator<Bullet>>(1, 30);

    auto parent = std::make_unique<GameObject>();
    parent->setName("GameParent");

    auto zombieWanderSound = std::make_unique<WanderSoundComponent>("Sounds/zombie-sound.mp3");
    zombieWanderSound->volume = 0.01;

    auto enemySpawner = std::make_unique<GameObject>();
    enemySpawner->addBehaviourScript(EnemySpawn(2000));
    enemySpawner->addComponent(std::move(zombieWanderSound));
    parent->addChild(std::move(enemySpawner));

    for (auto &go: levelBuilder.gameObjects) {
        parent->addChild(std::move(go));
    }

    auto spawnObject = parent->getChildGameObjectByName("PlayerSpawn");
    if (spawnObject.has_value()) {
        auto player = std::make_unique<Player>(spawnObject.value());
        parent->addChild(std::move(player));
    }

    parent->addChild(std::move(bulletPool));
    parent->addChild(std::move(enemyPool));

    auto progressBar = std::make_unique<ProgressBar>();
    parent->addChild(std::move(progressBar));

    auto wife = std::make_unique<Wife>(1,20);

    wife->tryGetComponent<TransformComponent>().position = std::make_unique<Vector2>(-400,0);

    parent->addChild(std::move(wife));

    parent->addChild(std::make_unique<PlayerHealthBar>());

    this->addGameObject(std::move(parent));

    auto pause = std::make_unique<PauseMenu>();
    this->addGameObject(std::move(pause));

    auto pauseHandler = std::make_unique<PauseManager>();
    this->addGameObject(std::move(pauseHandler));
}
