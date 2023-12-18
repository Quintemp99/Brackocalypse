//
// Created by Olaf van den Berg on 12-12-2023.
//

#include <Components/TransformComponent.hpp>
#include <Components/SpriteComponent.hpp>
#include "EnemySpawn.hpp"
#include "../Src/Enemy.hpp"
#include "../Src/Components/HealthComponent.hpp"
#include "RandomGenerator.hpp"
#include "../Src/Components/SpawnComponent.hpp"
#include "../Src/Components/WanderSoundComponent.hpp"

void EnemySpawn::onStart() {
}

void EnemySpawn::onUpdate(milliseconds deltaTime) {
    if(currentEnemyCount > 0){
        if(lastWanderSound <= 0){
            auto& wandersound = tryGetComponent<WanderSoundComponent>();
            wandersound.startPlaying = true;
            lastWanderSound = makeWanderSoundInterval;
        }else{
            lastWanderSound -= deltaTime;
        }
    }

    if(lastSpawned <= 0){
        lastSpawned = spawnInterval_;
        auto enemies = getGameObjectsByTag("Enemy");
        for (auto &enemy: enemies) {
            if (enemy->isActive()) {
                continue;
            }
            auto spawnObject = getGameObjectsByTag("EnemySpawner")[0];
            auto &transform = enemy->tryGetComponent<TransformComponent>();

            auto &spawnComponent = spawnObject->tryGetComponent<SpawnComponent>();
            auto spawnLocation =
                    spawnComponent.spawnLocations[RandomGenerator::randomInt(0,
                                                                             spawnComponent.spawnLocations.size() -
                                                                             1)].get();
            transform.position = std::make_unique<Vector2>(spawnLocation->getX(), spawnLocation->getY());


            enemy->setActive(true);
            auto &health = enemy->tryGetComponent<HealthComponent>();
            auto children = enemy->getChildren();
            for (auto& child: children) {
                if(child->getName() == "EnemyHealth"){
                    auto healthObjects = child->getChildren();
                    for (auto& healthObject: healthObjects) {
                        auto& sprite = healthObject->tryGetComponent<SpriteComponent>();
                        sprite.spritePath = "Sprites/heart_full.png";
                    }
                }
            }

            health.health = 3;
            currentEnemyCount++;
            break;
        }
    }else{
        lastSpawned -= deltaTime;
    }
}
