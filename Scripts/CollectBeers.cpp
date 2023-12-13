
#include <Components/BoxCollisionComponent.hpp>
#include "CollectBeers.hpp"
#include "PlayerProgress.hpp"

void CollectBeers::onStart() {}

void CollectBeers::onUpdate(float deltaTime) {
    if(!getActive())
        return;

    auto boxCollision = tryGetComponent<BoxCollisionComponent>();

    auto player = getGameObjectByTag("Player");
    for(auto& id : boxCollision.collidedWith) {
        if(player->getEntityId() == id) {
            PlayerProgress& script = player->tryGetBehaviourScript<PlayerProgress>();
            script.addBeer();
            setActive(false);
        }
    }
}