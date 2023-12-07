//
// Created by SKIKK on 24/11/2023.
//

#ifndef BRACKOCALYPSE_WALKINGSOUND_HPP
#define BRACKOCALYPSE_WALKINGSOUND_HPP


#include <Components/BehaviourScript.hpp>

class WalkingSound : public BehaviourScript {
public:
    WalkingSound() : BehaviourScript() {}

    ~WalkingSound() override = default;

    virtual void onStart() override;

    virtual void onUpdate(float deltaTime) override;

    std::unique_ptr<BehaviourScript> clone() const override {
        return std::make_unique<WalkingSound>(*this);
    }


    WalkingSound(const WalkingSound &other) : BehaviourScript(other) {}

    int getPriority() const { return priority; }

    int priority;

private:
    milliseconds intervalCounter = 100;
    milliseconds soundInterval = 500;
};


#endif //BRACKOCALYPSE_WALKINGSOUND_HPP
