#include "SpawnInBeers.hpp"
#include "../Src/Components/SpawnComponent.hpp"
#include <Components/TransformComponent.hpp>
#include <Components/BoxCollisionComponent.hpp>
#include <RandomGenerator.hpp>

void SpawnInBeers::onUpdate(milliseconds deltaTime) {
    auto spawnObject = getGameObjectByTag("BeerSpawner");
    auto &spawnComponent = spawnObject.value().tryGetComponent<SpawnComponent>();
    if(spawnComponent.availableSpawnLocations.size() > 0){
        if(lastSpawned <= 0){
            lastSpawned = spawnInterval_;
            auto beer = getGameObjectsByTag("Beer");
            for (auto &oneBeer: beer) {
                if (oneBeer->isActive()) {
                    continue;
                }

                auto &transform = oneBeer->tryGetComponent<TransformComponent>();

                int randomIndex = RandomGenerator::randomInt(0, spawnComponent.availableSpawnLocations.size() - 1);

                auto spawnLocation = *spawnComponent.availableSpawnLocations[randomIndex];

                spawnComponent.unavailableSpawnLocations.push_back(std::move(spawnComponent.availableSpawnLocations[randomIndex]));

                spawnComponent.availableSpawnLocations.erase(spawnComponent.availableSpawnLocations.begin() + randomIndex);

                transform.position = std::make_unique<Vector2>(spawnLocation.getX(), spawnLocation.getY());
                oneBeer->setActive(true);

                currentBeerCount++;
                break;
            }
        }else{
            lastSpawned -= deltaTime;
        }
    }
}

void SpawnInBeers::onStart() {

}
