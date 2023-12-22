#ifndef BRACKOCALYPSE_SPAWNINBEERS_HPP
#define BRACKOCALYPSE_SPAWNINBEERS_HPP

#include <BehaviourScripts/BehaviourScript.hpp>
#include <random>
#include <iostream>
#include <cstdlib>

class SpawnInBeers : public BehaviourScript {
public:
    SpawnInBeers(milliseconds spawnInterval) : BehaviourScript(), spawnInterval_(spawnInterval) {};
    ~SpawnInBeers() override = default;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<SpawnInBeers>(*this);
    }

    virtual void onStart() override;
    virtual void onUpdate(milliseconds deltaTime) override;

    SpawnInBeers(const SpawnInBeers &other) : BehaviourScript(other) {
        spawnInterval_ = other.spawnInterval_;
        lastSpawned = other.lastSpawned;
    }

private:
    int currentBeerCount = 0;
    milliseconds spawnInterval_;
    milliseconds lastSpawned = 0;
};


#endif //BRACKOCALYPSE_SPAWNINBEERS_HPP
