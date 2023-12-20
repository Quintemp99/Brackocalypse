//
// Created by Olaf van den Berg on 18-12-2023.
//

#ifndef BRACKOCALYPSE_MOVEMENTANIMATION_HPP
#define BRACKOCALYPSE_MOVEMENTANIMATION_HPP

#include "BehaviourScripts/BehaviourScript.hpp"


class MovementAnimation : public BehaviourScript {
public:
    MovementAnimation() : BehaviourScript() {
    }

    ~MovementAnimation() override = default;

    virtual void onStart() override;

    virtual void onUpdate(milliseconds deltaTime) override;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<MovementAnimation>(*this);
    }

    MovementAnimation(const MovementAnimation &other) : BehaviourScript(other) {
    }
};


#endif //BRACKOCALYPSE_MOVEMENTANIMATION_HPP
