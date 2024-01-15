//
// Created by qtemp on 21-12-2023.
//

#include "BossLevel.hpp"

#include "Components/SoundTrackComponent.hpp"
#include "EngineManagers/ReplayManager.hpp"
#include "../../../src/Scripts/FollowGameObject.hpp"
#include "../../LevelBuilder.hpp"
#include "../../Player.hpp"
#include "../../PlayerHealthBar.hpp"
#include "../../Wife.hpp"
#include "../../Bullet.hpp"
#include "../../Enemy.hpp"
#include "../../PoolCreator.hpp"
#include "../../Components/WanderSoundComponent.hpp"
#include "../../../src/Scripts/EnemySpawn.hpp"
#include "../../PauseMenu.hpp"
#include "../../PauseManager.hpp"
#include "../../WifeHealthBar.hpp"
#include "../../Components/HealthComponent.hpp"
#include "../../EnemyKillHud.hpp"

void BossLevel::build() {
    Scene::build();
    ReplayManager::getInstance().startRecording(10000, 100);

    auto camera = getAllCameras()[0];
    camera->addComponent(VelocityComponent());
    camera->SetBackgroundColor(Color(99, 197, 207, 255));
    camera->addBehaviourScript(FollowGameObject("Player"));
    camera->tryGetComponent<TransformComponent>().position = std::make_unique<Vector2>(-1200, -100);
    auto backgroundSound = std::make_unique<SoundTrackComponent>("Sounds/Fuck_me.mp3");
    backgroundSound->volume = 0.2;
    backgroundSound->startPlaying = true;
    camera->addComponent(std::move(backgroundSound));

    std::vector<std::vector<std::string>> objectMap{};
    std::vector<std::vector<std::string>> tileMap{};
    std::vector<std::string> collisionMap{};

    collisionMap.emplace_back("........................................................");
    collisionMap.emplace_back("........................................................");
    collisionMap.emplace_back("........................................................");
    collisionMap.emplace_back("........................................................");
    collisionMap.emplace_back("...................xxxxxxxxxxxxxxxxxxxxxxxxx............");
    collisionMap.emplace_back("..................x,,,,,,,,,,,,,,,,,,,,,,,,,x...........");
    collisionMap.emplace_back(".................xx,,,,,,,,,,x,,,,,,,,x,,,,,xx..........");
    collisionMap.emplace_back("................x,,,x,E,,x,,,,,,,x,,,,,,,,,,,,x.........");
    collisionMap.emplace_back("...............xx,,,,,,,,,,,,,,,,,,,,,,,,,,,,,xx........");
    collisionMap.emplace_back("..............x,,,,,,x,,,,,,,,,,,,,,,,,x,,,,,,,,x.......");
    collisionMap.emplace_back(".............xx,,,,,,,,,,,,,,,,,,,,,,,,,,,,E,,,,xx......");
    collisionMap.emplace_back("............x,,,,,,,,,,,,,,,,,x,x,,,,,,,,,,,,,x,,,x.....");
    collisionMap.emplace_back(".....xxxxxxxx,,,x,,,x,,,,,,,x,,,,,x,,,,,,,,x,,,,,,xx....");
    collisionMap.emplace_back("....x,,,,,,,,,,,,,,,,,,,,E,,,,,,,,,,,,,,,,,,,,,,,,,,x...");
    collisionMap.emplace_back("....x,,,,,,,,,,,,,x,,,,,,,,x,,,,,,,x,,,,,,,,,,x,,,,,x...");
    collisionMap.emplace_back("....x,,,x,,,,,x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x...");
    collisionMap.emplace_back("....x,,,,,,,,,,,,,,,,,x,,,,x,,,,,,,x,,,,x,,,,,,,,,,,x...");
    collisionMap.emplace_back("....x,,,,,x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x...");
    collisionMap.emplace_back(".....xxxxxxxx,,,,x,,,,,,,,,,x,,,,,x,,,,,,,,,x,,,,,,,x...");
    collisionMap.emplace_back("............x,,,,,,,,,,,,,,,,,x,x,,,,,,,,,,,,,,,,,xx....");
    collisionMap.emplace_back(".............xx,,,,,,x,,,,,,,,,,,,,,,,,,,,,,,,,,,,x.....");
    collisionMap.emplace_back("..............x.,,,,,,,,,,,,,,,,,,,,,,,x,,,,,x,,xx......");
    collisionMap.emplace_back("...............xx,,,,,,x,,,,,,,,x,,,,,,,,,,,,,,,x.......");
    collisionMap.emplace_back("................x,,,,,,,,E,,x,,,,,,,,,,,xE,,,,xx........");
    collisionMap.emplace_back(".................xx,,,,,,,,,,,,,,,,,,,,,,,,,,,x.........");
    collisionMap.emplace_back("..................x,,,,,,,,,,,,,,,,x,,,,,,,,xx..........");
    collisionMap.emplace_back("...................xx,,,,,,,,,,,,,,,,,,,,,,,x...........");
    collisionMap.emplace_back(".....................xxxxxxxxxxxxxxxxxxxxxxx............");
    collisionMap.emplace_back("........................................................");
    collisionMap.emplace_back("........................................................");
    collisionMap.emplace_back("........................................................");

    tileMap.emplace_back();
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWeWWWWWWWFWWWWWWWeWWWWWWWWWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWFWWWWWFWWWWWWFWWWWWWWWWWeWWWeWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWFWWWWWWeWWWWWWeWWWWWWWeWWWFWWWWFWWWWWWeWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWLQQQQQQQQQQQQQQQQQQQQQQQQQNWFWWWWWFWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWeWWWUGGGGGGGGGGGGGGGGGGGGGGGGGPWWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWFWWWWeWWFWWWLQMGGGGGGGGGGGGGGGGGGGGGGGGGBQNWFWWWeWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWUGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPWWFWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWFWWWWWLQMGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBQNWeWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWeWWWUGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWFWWWWLQMGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBQNFWWWW");
    tileMap[0].emplace_back("WWFWWeWWWWWeUGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPWWWWW");
    tileMap[0].emplace_back("WWWWLQQQQQQQMGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBQNeWW");
    tileMap[0].emplace_back("WWWWUGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPWWW");
    tileMap[0].emplace_back("WWWWUGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPWFW");
    tileMap[0].emplace_back("WWFWUGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPeWW");
    tileMap[0].emplace_back("WWWWUGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPWWW");
    tileMap[0].emplace_back("WWeWUGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPWFW");
    tileMap[0].emplace_back("WWWWVYYYYYYYXGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPWWW");
    tileMap[0].emplace_back("WWFWWWWWWWeWUGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGZYCFWW");
    tileMap[0].emplace_back("WWWWeWWWFWWWVYXGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWeWWWUGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGZYCWFWWW");
    tileMap[0].emplace_back("WWWWFWWWWWWFWWVYXGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPWWWeWWW");
    tileMap[0].emplace_back("WWWWWWeWWFWWWWWWUGGGGGGGGGGGGGGGGGGGGGGGGGGGGGZYCWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWVYXGGGGGGGGGGGGGGGGGGGGGGGGGGGPWWWWFWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWeWWFWWWWUGGGGGGGGGGGGGGGGGGGGGGGGGZYCWWWeWWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWVYXGGGGGGGGGGGGGGGGGGGGGGGPWWFWWWWWWWW");
    tileMap[0].emplace_back("WWWWWWWFWWWWeWWFWWWWVYYYYYYYYYYYYYYYYYYYYYYYCWWWWWWeWWWW");
    tileMap[0].emplace_back("WWWWWWWWWWWWWWWWWWWWeWWWWWeWWWWWFWWWWWWWeWWWWFWWWWWWWWWW");
    tileMap[0].emplace_back("WWWWWFWWWWWWWWWWWWFWWWWWFWWWWeWWWWWWWFWWWWFWWWWWWWWWWWWW");
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
    tileMap[1].emplace_back(".........................rmmmmmmmmmmmq..................");
    tileMap[1].emplace_back(".........................plllllllllllo..................");
    tileMap[1].emplace_back(".........................plllllllllllo..................");
    tileMap[1].emplace_back(".........................plllllllllllo..................");
    tileMap[1].emplace_back(".........................plllllllllllo..................");
    tileMap[1].emplace_back(".........................plllllllllllo..................");
    tileMap[1].emplace_back(".........................plllllllllllo..................");
    tileMap[1].emplace_back(".........................plllllllllllo..................");
    tileMap[1].emplace_back(".........................plllllllllllo..................");
    tileMap[1].emplace_back(".........................plllllllllllo..................");
    tileMap[1].emplace_back(".........................plllllllllllo..................");
    tileMap[1].emplace_back(".........................plllllllllllo..................");
    tileMap[1].emplace_back(".........................tnnnnnnnnnnns..................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");
    tileMap[1].emplace_back("........................................................");

    tileMap.emplace_back();
    tileMap[2].emplace_back("........................................................");
    tileMap[2].emplace_back("........................................................");
    tileMap[2].emplace_back("........................................................");
    tileMap[2].emplace_back("........................................................");
    tileMap[2].emplace_back("........................................................");
    tileMap[2].emplace_back("........................................................");
    tileMap[2].emplace_back(".............................K........K.................");
    tileMap[2].emplace_back("....................K....K.......K......................");
    tileMap[2].emplace_back("........................................................");
    tileMap[2].emplace_back(".....................K.................K................");
    tileMap[2].emplace_back("........................................................");
    tileMap[2].emplace_back("..............................u.u.............K.........");
    tileMap[2].emplace_back("................K...K.......u.....u........K............");
    tileMap[2].emplace_back("........................................................");
    tileMap[2].emplace_back("..................K........u.......u..........K.........");
    tileMap[2].emplace_back("........K.....K.........................................");
    tileMap[2].emplace_back("......................K....u.......u....K...............");
    tileMap[2].emplace_back("..........K.............................................");
    tileMap[2].emplace_back(".................K..........u.....u.........K...........");
    tileMap[2].emplace_back("..............................u.u.......................");
    tileMap[2].emplace_back(".....................K..................................");
    tileMap[2].emplace_back(".......................................K.....K..........");
    tileMap[2].emplace_back(".......................K........K.......................");
    tileMap[2].emplace_back("............................K...........K...............");
    tileMap[2].emplace_back("........................................................");
    tileMap[2].emplace_back("...................................K....................");
    tileMap[2].emplace_back("........................................................");
    tileMap[2].emplace_back("........................................................");
    tileMap[2].emplace_back("........................................................");
    tileMap[2].emplace_back("........................................................");
    tileMap[2].emplace_back("........................................................");

    tileMap.emplace_back();
    tileMap[3].emplace_back("........................................................");
    tileMap[3].emplace_back("........................................................");
    tileMap[3].emplace_back("........................................................");
    tileMap[3].emplace_back("........................................................");
    tileMap[3].emplace_back("........................................................");
    tileMap[3].emplace_back(".............................O........O.................");
    tileMap[3].emplace_back("....................O....O.......O......................");
    tileMap[3].emplace_back("........................................................");
    tileMap[3].emplace_back(".....................O........v.v......O................");
    tileMap[3].emplace_back("............................v.x.w.v.....................");
    tileMap[3].emplace_back("............................w.w.w.w...........O.........");
    tileMap[3].emplace_back("................O...O......vx.....wv.......O............");
    tileMap[3].emplace_back("...........................w.......w....................");
    tileMap[3].emplace_back("..................O........x.......x..........O.........");
    tileMap[3].emplace_back("........O.....O............x.......w....................");
    tileMap[3].emplace_back("......................O....wv.....vx....O...............");
    tileMap[3].emplace_back("..........O.................w.v.v.w.....................");
    tileMap[3].emplace_back(".................O..........w.w.x.w.........O...........");
    tileMap[3].emplace_back("..............................x.w.......................");
    tileMap[3].emplace_back(".....................O..................................");
    tileMap[3].emplace_back(".......................................O.....O..........");
    tileMap[3].emplace_back(".......................O........O.......................");
    tileMap[3].emplace_back("............................O...........O...............");
    tileMap[3].emplace_back("........................................................");
    tileMap[3].emplace_back("...................................O....................");
    tileMap[3].emplace_back("........................................................");
    tileMap[3].emplace_back("........................................................");
    tileMap[3].emplace_back("........................................................");
    tileMap[3].emplace_back("........................................................");
    tileMap[3].emplace_back("........................................................");
    tileMap[3].emplace_back("........................................................");

    tileMap.emplace_back();
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("...........................v.......v....................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");
    tileMap[4].emplace_back("........................................................");

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
    objectMap[0].emplace_back("........................................................");
    objectMap[0].emplace_back("............................d...........................");
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

    levelBuilder.buildLevel(MapType::Outdoor);

    auto enemyPool = std::make_unique<PoolCreator<Enemy>>(2, 30, 5, 16);
    auto bulletPool = std::make_unique<PoolCreator<Bullet>>(1, 30);

    auto parent = std::make_unique<GameObject>();
    parent->setName("GameParent");

    auto zombieWanderSound = std::make_unique<WanderSoundComponent>("Sounds/zombie-sound.mp3");
    zombieWanderSound->volume = 0.1;

    auto enemySpawner = std::make_unique<GameObject>();
    enemySpawner->addBehaviourScript(EnemySpawn(4000));
    enemySpawner->addComponent(std::move(zombieWanderSound));
    parent->addChild(std::move(enemySpawner));

    for (auto &go: levelBuilder.gameObjects) {
        parent->addChild(std::move(go));
    }

    auto player = std::make_unique<Player>(2, Vector2(-1200, -100));
    parent->addChild(std::move(player));

    parent->addChild(std::move(bulletPool));
    parent->addChild(std::move(enemyPool));

    auto wife = std::make_unique<Wife>(1, 20);

    wife->tryGetComponent<TransformComponent>().position = std::make_unique<Vector2>(250, -100);
    wife->tryGetComponent<SpriteComponent>().sortingLayer = 2;

    int wifeHealth = wife->tryGetComponent<HealthComponent>().maxHealth;

    auto enemyKillHud = std::make_unique<EnemyKillHud>();
    parent->addChild(std::move(enemyKillHud));

    parent->addChild(std::move(wife));
    parent->addChild(std::make_unique<PlayerHealthBar>());
    parent->addChild(std::make_unique<WifeHealthBar>(wifeHealth * 38));

    this->addGameObject(std::move(parent));

    auto pause = std::make_unique<PauseMenu>();
    this->addGameObject(std::move(pause));

    auto pauseHandler = std::make_unique<PauseManager>();
    this->addGameObject(std::move(pauseHandler));
}
