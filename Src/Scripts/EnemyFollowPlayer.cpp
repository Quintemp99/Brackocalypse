//
// Created by SKIKK on 14/12/2023.
//

#include <Components/TransformComponent.hpp>
#include <Components/AIComponent.hpp>
#include "EnemyFollowPlayer.hpp"

#include "Helpers/UserLogger.hpp"


void EnemyFollowPlayer::onStart() {
    try {
        auto &aiComponent = tryGetComponent<AIComponent>();
        auto graphGameobject = getGameObjectByName(graphName);
        if (!graphGameobject.has_value()) return;
        aiComponent.graphId = graphGameobject.value()->getEntityId();
    } catch (std::exception &e) {
        UserLogger::GetInstance().Error("EnemyFollowPlayer::onStart, crashed " + std::string(e.what()));
    }
}

void EnemyFollowPlayer::onUpdate(float deltaTime) {
    if (isActive) {
        auto &aiComponent = tryGetComponent<AIComponent>();

        auto player = getGameObjectByTag("Player");
        if (!player.has_value()) return;
        auto &playerTransform = player.value().tryGetComponent<TransformComponent>();

        if (aiComponent.target != playerTransform.position) {
            aiComponent.target = std::make_unique<Vector2>(*playerTransform.position);
        }
    }
}
