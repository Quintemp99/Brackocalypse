//
// Created by SKIKK on 14/12/2023.
//

#include <Components/TransformComponent.hpp>
#include <Components/AIComponent.hpp>
#include "EnemyFollowPlayer.hpp"


void EnemyFollowPlayer::onStart() {

}

void EnemyFollowPlayer::onUpdate(float deltaTime) {
    auto player = getGameObjectByTag("Player");
    if (!player.has_value()) return;
    auto &playerTransform = player.value().tryGetComponent<TransformComponent>();

    auto& aiComponent = tryGetComponent<AIComponent>();
    if(aiComponent.target != playerTransform.position){
        aiComponent.target = std::make_unique<Vector2>(*playerTransform.position);
    }
}