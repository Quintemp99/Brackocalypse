//
// Created by Olaf van den Berg on 12-12-2023.
//

#ifndef BRACKOCALYPSE_ENEMYSPAWN_HPP
#define BRACKOCALYPSE_ENEMYSPAWN_HPP


#include <BehaviourScripts/BehaviourScript.hpp>

class EnemySpawn : public BehaviourScript {

public:
    EnemySpawn(milliseconds spawnInterval) : BehaviourScript(), spawnInterval_(spawnInterval) {}

    ~EnemySpawn() override = default;

    void onStart() override;

    void onUpdate(milliseconds deltaTime) override;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<EnemySpawn>(*this);
    }

    EnemySpawn(const EnemySpawn &other) : BehaviourScript(other) {
        currentEnemyCount = other.currentEnemyCount;
        spawnInterval_ = other.spawnInterval_;
        lastSpawned = other.lastSpawned;
        makeWanderSoundInterval = other.makeWanderSoundInterval;
        lastWanderSound = other.lastWanderSound;
    }

private:
    int currentEnemyCount = 0;
    milliseconds spawnInterval_;
    milliseconds lastSpawned = 0;
    milliseconds makeWanderSoundInterval = 5000;
    milliseconds lastWanderSound = 2000;
};


#endif //BRACKOCALYPSE_ENEMYSPAWN_HPP
