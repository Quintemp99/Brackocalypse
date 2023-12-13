#ifndef BRACKOCALYPSE_SPAWNINBEERS_HPP
#define BRACKOCALYPSE_SPAWNINBEERS_HPP

#include <BehaviourScripts/BehaviourScript.hpp>
#include <random>
#include <iostream>
#include <cstdlib>

class SpawnInBeers : public BehaviourScript {
public:
    SpawnInBeers() : BehaviourScript() {};
    ~SpawnInBeers() override = default;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<SpawnInBeers>(*this);
    }

    virtual void onStart() override;
    virtual void onUpdate(float deltaTime) override;

    float getRandomNumber(int min, int max) {
        int range = max-min;
        int random = min + (std::rand() % range);
        auto randomNum = static_cast<float>(random);

        return randomNum;
    }
};


#endif //BRACKOCALYPSE_SPAWNINBEERS_HPP
