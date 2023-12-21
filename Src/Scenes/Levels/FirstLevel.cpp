//
// Created by Olaf van den Berg on 20-12-2023.
//

#include "FirstLevel.hpp"
#include <Components/AnimationComponent.hpp>
#include <Components/GraphComponent.hpp>
#include <Components/RectangleComponent.hpp>
#include "BrackEngine.hpp"
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
#include "../../PauseManager.hpp"
#include "../../ProgressBar.hpp"
#include "../../PlayerHealthBar.hpp"
#include "../../Components/WanderSoundComponent.hpp"
#include "../../../Scripts/SpawnInBeers.hpp"
#include "EngineManagers/ReplayManager.hpp"
#include "../../EnemyKillHud.hpp"

void FirstLevel::build() {
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
    collisionMap.emplace_back("......XXXXXXXXXXXXXXXX........XXXXXXXX........");
    collisionMap.emplace_back(".....X,E,,,,,,,,,,,,,,X......X,XXXXXX,X.......");
    collisionMap.emplace_back(".....X,,,,,,,,,,,,,,,,X......X,,,,,,,,X.......");
    collisionMap.emplace_back(".....X,,,,X,,,,,,X,,,,XXXXXXXX,,,B,,,,X.......");
    collisionMap.emplace_back(".....X,,,,,,,B,,,,,,,,,,,,,,,,,,,,,,,,X.......");
    collisionMap.emplace_back(".....X,,,,,,,,,,,,,,,,,,,B,,,,,,,,,,,,X.......");
    collisionMap.emplace_back(".....X,,,,,,,,,,,,,,,,XXXXXXXX,,,,,,,,X.......");
    collisionMap.emplace_back(".....X,,,,X,,,,,,X,,,,X......X,,,,,,,,X.......");
    collisionMap.emplace_back(".....X,,B,,,,,,,,,,,,,X......X,,,,,,E,X.......");
    collisionMap.emplace_back("......XXXXXXX,,XXXXXXX........XXXXXXXX........");
    collisionMap.emplace_back("............X,,X..............................");
    collisionMap.emplace_back("............X,,X..............................");
    collisionMap.emplace_back("............X,,X..............................");
    collisionMap.emplace_back("............X,,X..............................");
    collisionMap.emplace_back("........XXXXX,,XXXXXXX........................");
    collisionMap.emplace_back(".......X,,,,,,,,X,,,,,X.........XXXXXXXXX.....");
    collisionMap.emplace_back(".......X,,,,,,,,,,,,,,X........X,,,,,,,,,X....");
    collisionMap.emplace_back(".......Xx,,,,,,,,,,B,,XXXXXXXXXX,,B,,,,E,X....");
    collisionMap.emplace_back(".......X,,,,,,,,,,,,,,,,,,B,,,,,,,,,,,,,,X....");
    collisionMap.emplace_back(".......X,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,X....");
    collisionMap.emplace_back(".......X,,,,,,,,,,,,,,XXXXXXXXXX,,,,,,,,,X....");
    collisionMap.emplace_back(".......X,,B,,,,,,,,,,,X........X,,,xxx,B,X....");
    collisionMap.emplace_back(".......X,E,,,,,,,,,,,,X........X,,,xxx,,,X....");
    collisionMap.emplace_back("........XXXXXXXXXXXXXX.........X,,,,,,,,,X....");
    collisionMap.emplace_back("...............................X,E,,,,,,,X....");
    collisionMap.emplace_back("................................XXXXXXXXX.....");
    collisionMap.emplace_back("..............................................");
    collisionMap.emplace_back("..............................................");
    collisionMap.emplace_back("..............................................");

    tileMap.emplace_back();
    tileMap[0].emplace_back("..............................................");
    tileMap[0].emplace_back(".........ABBBC................................");
    tileMap[0].emplace_back(".........DHIJD................................");
    tileMap[0].emplace_back(".........DKFLD................................");
    tileMap[0].emplace_back(".........DONMD................................");
    tileMap[0].emplace_back(".....ABBBQBBBQBBBBBBBBC......ABBBBBBBBC.......");
    tileMap[0].emplace_back(".....DHIIIIIIIIIIIIIIJD......DmwnwnwnxD.......");
    tileMap[0].emplace_back(".....DKFFFFFFFFFFFFFFLD......DylululuqD.......");
    tileMap[0].emplace_back(".....DKFFFFFFFFFFFFFFLEBBBBBBGpulululzD.......");
    tileMap[0].emplace_back(".....DKFFFFFFFFFFFFFFFIIIIIIInulululuqD.......");
    tileMap[0].emplace_back(".....DKFFFFFFFFFFFFFFFNNNNNNN2lulululzD.......");
    tileMap[0].emplace_back(".....DKFFFFFFFFFFFFFFLABBBBBBCylululuqD.......");
    tileMap[0].emplace_back(".....DKFFFFFFFFFFFFFFLD......DpulululzD.......");
    tileMap[0].emplace_back(".....DONNNNNNFFNNNNNNMD......D1s2s2s2tD.......");
    tileMap[0].emplace_back(".....EBBBBBBCKLABBBBBBG......EBBBBBBBBG.......");
    tileMap[0].emplace_back("............DKLD..............................");
    tileMap[0].emplace_back("............DKLD..............................");
    tileMap[0].emplace_back("............DKLD..............................");
    tileMap[0].emplace_back("............DKLD..............................");
    tileMap[0].emplace_back(".......ABBBBGKLEBBBBBBC.......................");
    tileMap[0].emplace_back(".......DHIIIIFFIIIIIIJD........ABBBBBBBBBC....");
    tileMap[0].emplace_back(".......DKFFFFFFFFFFFFLD........DHIIIIIIIJD....");
    tileMap[0].emplace_back(".......DKFFFFFFFFFFFFLEBBBBBBBBGKFFFFFFFLD....");
    tileMap[0].emplace_back(".......DKFFFFFFFFFFFFFIIIIIIIIIIFFFFFFFFLD....");
    tileMap[0].emplace_back(".......DKFFFFFFFFFFFFFNNNNNNNNNNFFFFFFFFLD....");
    tileMap[0].emplace_back(".......DKFFFFFFFFFFFFLABBBBBBBBCKFFFFFFFLD....");
    tileMap[0].emplace_back(".......DKFFFFFFFFFFFFLD........DKFFFFFFFLD....");
    tileMap[0].emplace_back(".......DONNNNNNNNNNNNMD........DKFFFFFFFLD....");
    tileMap[0].emplace_back(".......EBBBBBBBBBBBBBBG........DKFFFFFFFLD....");
    tileMap[0].emplace_back("...............................DONNNNNNNMD....");
    tileMap[0].emplace_back("...............................EBBBBBBBBBG....");
    tileMap[0].emplace_back("..............................................");
    tileMap[0].emplace_back("..............................................");
    tileMap[0].emplace_back("..............................................");

    tileMap.emplace_back();
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..........c.b.................................");
    tileMap[1].emplace_back("............a.................................");
    tileMap[1].emplace_back("..........a...................................");
    tileMap[1].emplace_back("...........P........................g.........");
    tileMap[1].emplace_back("...............................edfeee.........");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..........4......4............................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..........4......4............................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..........i...................................");
    tileMap[1].emplace_back("................k.................RSST........");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("........h.....................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("..............................................");
    tileMap[1].emplace_back("...................................UUU........");
    tileMap[1].emplace_back("...................................VVV........");
    tileMap[1].emplace_back("..............................................");
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
    tileMap[2].emplace_back("..........6......6............................");
    tileMap[2].emplace_back("..........5......5............................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..........6......6............................");
    tileMap[2].emplace_back("..........5......5............................");
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
    tileMap[2].emplace_back("...................................WYX........");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");
    tileMap[2].emplace_back("..............................................");


    objectMap.emplace_back();
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("..............................................");
    objectMap[0].emplace_back("...............j..............................");
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
    objectMap[0].emplace_back("........d.....................................");
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

    auto levelBuilder = LevelBuilder(objectMap, tileMap, collisionMap);

    levelBuilder.buildLevel(MapType::Indoor);

    auto bulletPool = std::make_unique<PoolCreator<Bullet>>(1, 30);
    auto enemyPool = std::make_unique<PoolCreator<Enemy>>(1, 30, 3,20);
    auto beerPool = std::make_unique<PoolCreator<Beer>>(1, 10);
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
