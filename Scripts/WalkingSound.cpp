//
// Created by SKIKK on 24/11/2023.
//

#include <EngineManagers/InputManager.hpp>
#include <Helpers/KeyMap.hpp>
#include <Components/SoundEffectComponent.hpp>
#include "WalkingSound.hpp"

void WalkingSound::onStart() {}

void WalkingSound::onUpdate(milliseconds deltaTime) {
    auto& audioComponent = tryGetComponent<SoundEffectComponent>();

    if (InputManager::GetInstance().IsKeyPressed(KeyMap::w) || InputManager::GetInstance().IsKeyPressed(KeyMap::UP)) {
        intervalCounter -= deltaTime;
    } else if (InputManager::GetInstance().IsKeyPressed(KeyMap::s) || InputManager::GetInstance().IsKeyPressed(KeyMap::DOWN)) {
        intervalCounter -= deltaTime;
    }

    if (InputManager::GetInstance().IsKeyPressed(KeyMap::a) || InputManager::GetInstance().IsKeyPressed(KeyMap::LEFT)) {
        intervalCounter -= deltaTime;
    } else if (InputManager::GetInstance().IsKeyPressed(KeyMap::d) || InputManager::GetInstance().IsKeyPressed(KeyMap::RIGHT)) {
        intervalCounter -= deltaTime;
    }

    if(intervalCounter <= 0.0){
        audioComponent.startPlaying = true;
        intervalCounter = soundInterval;
    }
}