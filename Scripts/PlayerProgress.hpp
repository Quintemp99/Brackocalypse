//
// Created by stijn on 6-12-2023.
//

#ifndef BRACKOCALYPSE_PLAYERPROGRESS_HPP
#define BRACKOCALYPSE_PLAYERPROGRESS_HPP

#include <BehaviourScripts/BehaviourScript.hpp>

class PlayerProgress : public BehaviourScript {
public:
    PlayerProgress() : BehaviourScript() {
        maxForLevel = 10;
        beersCollected = 0;
        foodCollected = 0;
    }

    ~PlayerProgress() override = default;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<PlayerProgress>(*this);
    }

    PlayerProgress(const PlayerProgress &other) : BehaviourScript(other) {
        maxForLevel = other.maxForLevel;
        beersCollected = other.beersCollected;
        foodCollected = other.foodCollected;
    }

    virtual void onStart() override;

    virtual void onUpdate(milliseconds deltaTime) override;

    void addBeer() { ++beersCollected; }

    void addFood() { ++foodCollected; }

    int getBeersCollected() { return beersCollected; }

    void setBeersCollected(int amount) { beersCollected = amount; }

private:
    int maxForLevel;
    int beersCollected;
    int foodCollected;
};


#endif //BRACKOCALYPSE_PLAYERPROGRESS_HPP
