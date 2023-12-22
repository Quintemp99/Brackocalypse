//
// Created by jesse on 19/12/2023.
//

#ifndef BRACKOCALYPSE_PLAYBOXMOVINGSOUND_HPP
#define BRACKOCALYPSE_PLAYBOXMOVINGSOUND_HPP


#include <BehaviourScripts/BehaviourScript.hpp>

class PlayBoxMovingSound : public BehaviourScript {
public:
    PlayBoxMovingSound() : BehaviourScript() {
    };

    ~PlayBoxMovingSound() override = default;

    virtual void onStart() override;

    virtual void onUpdate(milliseconds deltaTime) override;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<PlayBoxMovingSound>(*this);
    }

    PlayBoxMovingSound(const PlayBoxMovingSound &other) : BehaviourScript(other) {
        timer = other.timer;
        interval = other.interval;
        canPlay = other.canPlay;
    };

private:
    milliseconds timer = 0.0f;
    milliseconds interval = 1000.0f;
    bool canPlay = true;
    CollisionArchetype& getCollisionComponent();
    CollisionArchetype& getCollisionComponent(entity id);
};


#endif //BRACKOCALYPSE_PLAYBOXMOVINGSOUND_HPP
