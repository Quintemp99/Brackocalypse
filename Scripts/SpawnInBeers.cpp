#include "SpawnInBeers.hpp"
#include <Components/TransformComponent.hpp>
#include <Components/BoxCollisionComponent.hpp>

void SpawnInBeers::onUpdate(milliseconds deltaTime) {
    for (auto &beer: getGameObjectsByTag("Beer")) {
        if (!beer->isActive()) {
            auto& transform = beer->tryGetComponent<TransformComponent>();
            transform.position->setX(getRandomNumber(-1080, -280));
            transform.position->setY(getRandomNumber(-190, 510));

            auto player = getGameObjectByTag("Player");
            auto& transformComponentPlayer = player->tryGetComponent<TransformComponent>();
            float distance = transformComponentPlayer.position->distance(*transform.position);
            if(distance < 300)
                break;

            beer->setActive(true);
        }
    }
}

void SpawnInBeers::onStart() {
    IBehaviourScript::onStart();
}
