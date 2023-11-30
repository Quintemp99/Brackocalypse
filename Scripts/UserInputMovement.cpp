//
// Created by SKIKK on 17/11/2023.
//

#include <EngineManagers/InputManager.hpp>
#include <Helpers/KeyMap.hpp>
#include "UserInputMovement.hpp"

void UserInputMovement::onStart() {}

void UserInputMovement::onUpdate(milliseconds deltaTime) {
    auto& playerVelocityComponent = tryGetComponent<VelocityComponent>();

    if (InputManager::GetInstance().IsKeyPressed(KeyMap::w) || InputManager::GetInstance().IsKeyPressed(KeyMap::UP)) {
        playerVelocityComponent.velocity.setY(-velocity);
    } else if (InputManager::GetInstance().IsKeyPressed(KeyMap::s) || InputManager::GetInstance().IsKeyPressed(KeyMap::DOWN)) {
        playerVelocityComponent.velocity.setY(velocity);
    } else {
        playerVelocityComponent.velocity.setY(0);
    }
    if (InputManager::GetInstance().IsKeyPressed(KeyMap::a) || InputManager::GetInstance().IsKeyPressed(KeyMap::LEFT)) {
        playerVelocityComponent.velocity.setX(-velocity);
    } else if (InputManager::GetInstance().IsKeyPressed(KeyMap::d) || InputManager::GetInstance().IsKeyPressed(KeyMap::RIGHT)) {
        playerVelocityComponent.velocity.setX(velocity);
    } else {
        playerVelocityComponent.velocity.setX(0);
    }
}