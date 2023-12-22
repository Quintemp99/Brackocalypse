//
// Created by Stef van Stipdonk on 15/12/2023.
//

#ifndef BRACKOCALYPSE_TOGGLEFPS_HPP
#define BRACKOCALYPSE_TOGGLEFPS_HPP


#include "BehaviourScripts/BehaviourScript.hpp"

class ToggleFPS : public BehaviourScript {
public:
    ToggleFPS() : BehaviourScript() {
    }

    ~ToggleFPS() override = default;

    virtual void onStart() override;

    virtual void onUpdate(float deltaTime) override;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<ToggleFPS>(*this);
    }


    ToggleFPS(const ToggleFPS &other) : BehaviourScript(other) {
    }
};


#endif //BRACKOCALYPSE_TOGGLEFPS_HPP
