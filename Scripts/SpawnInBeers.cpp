#include "SpawnInBeers.hpp"
#include <Components/TransformComponent.hpp>

void SpawnInBeers::onUpdate(float deltaTime) {
    for (auto &bullet: getGameObjectsByTag("Beer")) {
        if (!bullet->isActive()) {
            auto& transform = bullet->tryGetComponent<TransformComponent>();
            transform.position->setX(getRandomNumber(-1080, -280));
            transform.position->setY(getRandomNumber(-190, 610));

            bullet->setActive(true);
        }
    }
}

void SpawnInBeers::onStart() {
    IBehaviourScript::onStart();
}
