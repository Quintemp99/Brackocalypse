//
// Created by jesse on 04/12/2023.
//

#ifndef BRACKOCALYPSE_BULLETACTIONS_HPP
#define BRACKOCALYPSE_BULLETACTIONS_HPP


#include <BehaviourScripts/BehaviourScript.hpp>

class BulletActions : public BehaviourScript {
public:
    BulletActions(milliseconds lifeTime) : BehaviourScript(), lifeTime(lifeTime) {}

    ~BulletActions() override = default;

    virtual void onStart() override;

    virtual void onUpdate(milliseconds deltaTime) override;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<BulletActions>(*this);
    }

    BulletActions(const BulletActions &other) : BehaviourScript(other) {
        lifeTime = other.lifeTime;
        timer = other.timer;
        wifeTimer = other.wifeTimer;
        wifeTime = other.wifeTime;
        canHitWife = other.canHitWife;
    }

    void setInactive();

private:
    milliseconds lifeTime;
    milliseconds timer = 0.0f;
    milliseconds wifeTimer = 0.0f;
    milliseconds wifeTime = 2000.0f;
    bool canHitWife = true;
};


#endif //BRACKOCALYPSE_BULLETACTIONS_HPP
