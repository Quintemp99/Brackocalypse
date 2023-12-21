//
// Created by qtemp on 21-12-2023.
//

#include "BossLevel.hpp"

#include "Components/SoundTrackComponent.hpp"
#include "EngineManagers/ReplayManager.hpp"
#include "../../../Scripts/FollowGameObject.hpp"

void BossLevel::build()
{
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


    collisionMap.emplace_back("......................................................................");
    collisionMap.emplace_back("......................................................................");
    collisionMap.emplace_back("......................................................................");
    collisionMap.emplace_back("......................................................................");
    collisionMap.emplace_back("......................................................................");
    collisionMap.emplace_back("......................................................................");
    collisionMap.emplace_back(".........................xxxxxxxxxxxxxxxxxxxxxxxxxxx..................");
    collisionMap.emplace_back("........................x...........................x.................");
    collisionMap.emplace_back(".......................x.............................x................");
    collisionMap.emplace_back("......................x...............................x...............");
    collisionMap.emplace_back(".....................x.................................x..............");
    collisionMap.emplace_back("....................x...................................x.............");
    collisionMap.emplace_back("...................x.....................................x............");
    collisionMap.emplace_back("..................x.......................................x...........");
    collisionMap.emplace_back(".xxxxxxxxxxxxxxxxx.........................................x..........");
    collisionMap.emplace_back("x..........................................................x..........");
    collisionMap.emplace_back("x..........................................................x..........");
    collisionMap.emplace_back("x..........................................................x..........");
    collisionMap.emplace_back("x..........................................................x..........");
    collisionMap.emplace_back("x..........................................................x..........");
    collisionMap.emplace_back(".xxxxxxxxxxxxxxxxx.........................................x..........");
    collisionMap.emplace_back("..................x.......................................x...........");
    collisionMap.emplace_back("...................x.....................................x............");
    collisionMap.emplace_back("....................x...................................x.............");
    collisionMap.emplace_back(".....................x.................................x..............");
    collisionMap.emplace_back("......................x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x...............");
    collisionMap.emplace_back(".......................x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,x................");
    collisionMap.emplace_back("........................x,,,,,,,,,,,,,,,,,,,,,,,,,,,x.................");
    collisionMap.emplace_back(".........................xxxxxxxxxxxxxxxxxxxxxxxxxxx..................");
    collisionMap.emplace_back("......................................................................");
    collisionMap.emplace_back("......................................................................");
    collisionMap.emplace_back("......................................................................");
    collisionMap.emplace_back("......................................................................");
}
