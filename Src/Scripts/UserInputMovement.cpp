//
// Created by SKIKK on 17/11/2023.
//

#include <EngineManagers/InputManager.hpp>
#include <Helpers/KeyMap.hpp>
#include <Components/SoundEffectComponent.hpp>
#include <Components/SpriteComponent.hpp>
#include <Components/TransformComponent.hpp>
#include <Components/BoxCollisionComponent.hpp>
#include "UserInputMovement.hpp"
#include "Components/VelocityComponent.hpp"

void UserInputMovement::onStart() {}

void UserInputMovement::onUpdate(milliseconds deltaTime) {
    auto &playerVelocityComponent = tryGetComponent<VelocityComponent>();
    auto &spriteComponent = tryGetComponent<SpriteComponent>();
    auto &walkAnimation = tryGetComponent<AnimationComponent>();

    auto &playerTransform = tryGetComponent<TransformComponent>();
    auto playerCollision = getGameObjectByTag("PlayerCollision");
    auto &playerCollisionTransform = playerCollision->tryGetComponent<TransformComponent>();
    auto gun = getGameObjectByTag("Gun");
    auto &gunTransform = gun->tryGetComponent<TransformComponent>();

//    auto &soundEffect = tryGetComponent<SoundEffectComponent>();

    int left = static_cast<int>(InputManager::getInstance().IsKeyPressed(KeyMap::a) ||
                                InputManager::getInstance().IsKeyPressed(KeyMap::LEFT));
    int right = static_cast<int>(InputManager::getInstance().IsKeyPressed(KeyMap::d) ||
                                 InputManager::getInstance().IsKeyPressed(KeyMap::RIGHT));
    int up = static_cast<int>(InputManager::getInstance().IsKeyPressed(KeyMap::w) ||
                              InputManager::getInstance().IsKeyPressed(KeyMap::UP));
    int down = static_cast<int>(InputManager::getInstance().IsKeyPressed(KeyMap::s) ||
                                InputManager::getInstance().IsKeyPressed(KeyMap::DOWN));


    auto horizontalMovement = right - left;
    auto verticalMovement = down - up;

    float magnitude = std::sqrt(horizontalMovement * horizontalMovement + verticalMovement * verticalMovement);

    // Normalize the movement vector (make sure its length is 1)
    float normalizedHorizontalMovement = (magnitude > 0) ? horizontalMovement / magnitude : 0;
    float normalizedVerticalMovement = (magnitude > 0) ? verticalMovement / magnitude : 0;

    // Set the player's velocity based on the normalized input and desired speed
    playerVelocityComponent.velocity.setX(normalizedHorizontalMovement * velocity);
    playerVelocityComponent.velocity.setY(normalizedVerticalMovement * velocity);
}