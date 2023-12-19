
#include <Components/BoxCollisionComponent.hpp>
#include "CollectBeers.hpp"
#include "PlayerProgress.hpp"
#include "../Src/Beer.hpp"
#include "../Src/Components/SpawnComponent.hpp"

void CollectBeers::onStart() {}

void CollectBeers::onUpdate(milliseconds deltaTime) {
    auto &boxCollision = tryGetComponent<BoxCollisionComponent>();

    auto player = getGameObjectByTag("Player");
    for (auto &id: boxCollision.collidedWith) {
        if (player->getEntityId() == id) {
            setActive(false);
            boxCollision.collidedWith.clear();
            PlayerProgress &script = player->tryGetBehaviourScript<PlayerProgress>();
            tryGetComponent<SoundEffectComponent>().startPlaying = true;
            script.addBeer();

            auto playerLocation = player->tryGetComponent<TransformComponent>().position.get();
            auto spawnObject = getGameObjectByTag("BeerSpawner");
            auto &spawnComponent = spawnObject->tryGetComponent<SpawnComponent>();

            auto closestPositionIter = std::min_element(
                    spawnComponent.unavailableSpawnLocations.begin(),
                    spawnComponent.unavailableSpawnLocations.end(),
                    [playerLocation](const auto& a, const auto& b) {
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