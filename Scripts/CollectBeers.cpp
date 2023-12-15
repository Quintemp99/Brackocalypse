
#include <Components/BoxCollisionComponent.hpp>
#include "CollectBeers.hpp"
#include "PlayerProgress.hpp"
#include "../Src/Beer.hpp"

void CollectBeers::onStart() {}

void CollectBeers::onUpdate(milliseconds deltaTime) {
    auto &boxCollision = tryGetComponent<BoxCollisionComponent>();

    auto player = getGameObjectByTag("Player");
    for (auto &id: boxCollision.collidedWith) {
        if (player->getEntityId() == id) {
            setActive(false);
            boxCollision.collidedWith.clear();
            PlayerProgress &script = player->tryGetBehaviourScript<PlayerProgress>();
            script.addBeer();

            return;
        }
    }
}