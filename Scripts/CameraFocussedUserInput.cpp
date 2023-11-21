//
// Created by SKIKK on 17/11/2023.
//

#include "CameraFocussedUserInput.hpp"

void CameraFocussedUserInput::onStart() {}

void CameraFocussedUserInput::onUpdate(float deltaTime) {
    auto& velocityComponent = ComponentStore::GetInstance().tryGetComponent<VelocityComponent>(entityID);
    auto cameraId = ComponentStore::GetInstance().getEntitiesWithComponent<CameraComponent>()[0];
    auto& cameraVelocityComponent = ComponentStore::GetInstance().tryGetComponent<VelocityComponent>(cameraId);

    if (InputManager::GetInstance().IsKeyPressed(KeyMap::w) || InputManager::GetInstance().IsKeyPressed(KeyMap::UP)) {
        velocityComponent.velocity.setY(-velocity);
        cameraVelocityComponent.velocity.setY(-velocity);
    } else if (InputManager::GetInstance().IsKeyPressed(KeyMap::s) || InputManager::GetInstance().IsKeyPressed(KeyMap::DOWN)) {
        velocityComponent.velocity.setY(velocity);
        cameraVelocityComponent.velocity.setY(velocity);
    } else {
        velocityComponent.velocity.setY(0);
        cameraVelocityComponent.velocity.setY(0);
    }
    if (InputManager::GetInstance().IsKeyPressed(KeyMap::a) || InputManager::GetInstance().IsKeyPressed(KeyMap::LEFT)) {
        velocityComponent.velocity.setX(-velocity);
        cameraVelocityComponent.velocity.setX(-velocity);
    } else if (InputManager::GetInstance().IsKeyPressed(KeyMap::d) || InputManager::GetInstance().IsKeyPressed(KeyMap::RIGHT)) {
        velocityComponent.velocity.setX(velocity);
        cameraVelocityComponent.velocity.setX(velocity);
    } else {
        velocityComponent.velocity.setX(0);
        cameraVelocityComponent.velocity.setX(0);
    }
}