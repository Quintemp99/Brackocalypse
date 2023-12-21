//
// Created by stijn on 6-12-2023.
//

#ifndef BRACKOCALYPSE_PLAYERPROGRESS_HPP
#define BRACKOCALYPSE_PLAYERPROGRESS_HPP

#include <BehaviourScripts/BehaviourScript.hpp>

class PlayerProgress : public BehaviourScript {
public:
    PlayerProgress(int beersNeeded) : BehaviourScript() {
        this->beersNeeded = beersNeeded;
        beersCollected = 0;
    }

    ~PlayerProgress() override = default;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<PlayerProgress>(*this);
    }

    PlayerProgress(const PlayerProgress &other) : BehaviourScript(other) {
        beersNeeded = other.beersNeeded;
        beersCollected = other.beersCollected;
    }

    virtual void onStart() override;

    virtual void onUpdate(milliseconds deltaTime) override;

    void addBeer();

    int getBeersCollected() { return beersCollected; }

    void setBeersCollected(int amount) { beersCollected = amount; }

private:
    int beersNeeded;
    int beersCollected;
};


#endif //BRACKOCALYPSE_PLAYERPROGRESS_HPP
