//
// Created by stijn on 6-12-2023.
//

#ifndef BRACKOCALYPSE_PLAYERPROGRESS_HPP
#define BRACKOCALYPSE_PLAYERPROGRESS_HPP

#include <BehaviourScripts/BehaviourScript.hpp>

class PlayerProgress : public BehaviourScript {
public:
    PlayerProgress() : BehaviourScript() {}
    ~PlayerProgress() override = default;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<PlayerProgress>(*this);
    }

    virtual void onStart() override;
    virtual void onUpdate(float deltaTime) override;

    void addBeer() { ++beersCollected; }
    void addFood() { ++foodCollected; }
private:
    int maxForLevel = 10;
    int beersCollected = 0;
    int foodCollected = 0;
};


#endif //BRACKOCALYPSE_PLAYERPROGRESS_HPP
