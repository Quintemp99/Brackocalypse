//
// Created by SKIKK on 17/11/2023.
//

#include "CameraFocussedUserInput.hpp"

void CameraFocussedUserInput::onStart() {}

void CameraFocussedUserInput::onUpdate(float deltaTime) {
    auto& playerVelocityComponent = tryGetComponent<VelocityComponent>();
    auto camera = getGameObjectByTag("mainCamera");

    if(!camera.has_value()) return;

    auto& cameraVelocityComponent = camera.value().tryGetComponent<VelocityComponent>();

    if (InputManager::GetInstance().IsKeyPressed(KeyMap::w) || InputManager::GetInstance().IsKeyPressed(KeyMap::UP)) {
        playerVelocityComponent.velocity.setY(-velocity);
        cameraVelocityComponent.velocity.setY(-velocity);
    } else if (InputManager::GetInstance().IsKeyPressed(KeyMap::s) || InputManager::GetInstance().IsKeyPressed(KeyMap::DOWN)) {
        playerVelocityComponent.velocity.setY(velocity);
        cameraVelocityComponent.velocity.setY(velocity);
    } else {
        playerVelocityComponent.velocity.setY(0);
        cameraVelocityComponent.velocity.setY(0);
    }
    if (InputManager::GetInstance().IsKeyPressed(KeyMap::a) || InputManager::GetInstance().IsKeyPressed(KeyMap::LEFT)) {
        playerVelocityComponent.velocity.setX(-velocity);
        cameraVelocityComponent.velocity.setX(-velocity);
    } else if (InputManager::GetInstance().IsKeyPressed(KeyMap::d) || InputManager::GetInstance().IsKeyPressed(KeyMap::RIGHT)) {
        playerVelocityComponent.velocity.setX(velocity);
        cameraVelocityComponent.velocity.setX(velocity);
    } else {
        playerVelocityComponent.velocity.setX(0);
        cameraVelocityComponent.velocity.setX(0);
    }
}