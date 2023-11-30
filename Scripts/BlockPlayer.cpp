//
// Created by Olaf van den Berg on 28-11-2023.
//

#include <Components/CircleCollisionComponent.hpp>
#include <Components/BoxCollisionComponent.hpp>
#include "BlockPlayer.hpp"

void BlockPlayer::onStart() {
}

void BlockPlayer::onUpdate(float deltaTime) {
    auto player = getGameObjectByTag("Player");
    if (!player.has_value()) return;
    auto &playerCollision = player.value().tryGetComponent<BoxCollisionComponent>();
    for (auto i: playerCollision.collidedWith) {
        auto collidedWith = ComponentStore::GetInstance().tryGetComponent<BoxCollisionComponent>(i);
        

        Logger::GetInstance().Debug("Collided with: " + std::to_string(i));
    }


}


