
#include <Components/BoxCollisionComponent.hpp>
#include "CollectBeers.hpp"
#include "PlayerProgressScript.hpp"
#include <Components/SoundEffectComponent.hpp>
#include <Components/TransformComponent.hpp>
#include "../Components/SpawnComponent.hpp"

void CollectBeers::onStart() {
}

void CollectBeers::onUpdate(milliseconds deltaTime) {
    auto &boxCollision = tryGetComponent<BoxCollisionComponent>();

    auto playerCollision = getGameObjectByTag("PlayerCollision");
    for (auto &id: boxCollision.collidedWith) {
        if (playerCollision->getEntityId() == id) {
            setActive(false);
            boxCollision.collidedWith.clear();
            auto playerProgress = getGameObjectByName("PlayerProgress");
            PlayerProgressScript &script = playerProgress.value()->tryGetBehaviourScript<PlayerProgressScript>();
            tryGetComponent<SoundEffectComponent>().startPlaying = true;
            script.addBeer();

            auto playerLocation = playerCollision->getParent().value().tryGetComponent<TransformComponent>().position.
                    get();
            auto spawnObject = getGameObjectByTag("BeerSpawner");
            auto &spawnComponent = spawnObject->tryGetComponent<SpawnComponent>();

            auto closestPositionIter = std::min_element(
                spawnComponent.unavailableSpawnLocations.begin(),
                spawnComponent.unavailableSpawnLocations.end(),
                [playerLocation](const auto &a, const auto &b) {
                    return a->distance(*playerLocation) < b->distance(*playerLocation);
                }
            );

            if (closestPositionIter != spawnComponent.unavailableSpawnLocations.end()) {
                // Move the unique pointer from unavailable to available
                spawnComponent.availableSpawnLocations.push_back(std::move(*closestPositionIter));
                spawnComponent.unavailableSpawnLocations.erase(closestPositionIter);
            }

            break;
        }
    }
}
