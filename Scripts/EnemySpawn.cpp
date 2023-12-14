//
// Created by Olaf van den Berg on 12-12-2023.
//

#include <Components/TransformComponent.hpp>
#include "EnemySpawn.hpp"
#include "../Src/Enemy.hpp"
#include "../Src/Components/HealthComponent.hpp"
#include "RandomGenerator.hpp"
#include "../Src/Components/SpawnComponent.hpp"

void EnemySpawn::onStart() {
}

void EnemySpawn::onUpdate(milliseconds deltaTime) {
    if (currentEnemyCount != 0) {
        return;
    }
    if (currentWave > sizeof(waves) / sizeof(waves[0])) {
        currentWave = sizeof(waves) / sizeof(waves[0]);
    }
    for (int i = 0; i < waves[currentWave - 1]; i++) {
        auto enemies = getGameObjectsByTag("Enemy");
        for (auto &enemy: enemies) {

            if (enemy->isActive()) {
                break;
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

            health.health = 3;
            currentEnemyCount++;
            break;
        }
    }

    currentWave++;


}
