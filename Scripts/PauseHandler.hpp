//
// Created by Stef van Stipdonk on 12/12/2023.
//

#ifndef BRACKOCALYPSE_PAUSEHANDLER_HPP
#define BRACKOCALYPSE_PAUSEHANDLER_HPP


#include "BehaviourScripts/BehaviourScript.hpp"

class PauseHandler : public BehaviourScript {
public:
    PauseHandler() : BehaviourScript() {}

    ~PauseHandler() override = default;

    virtual void onStart() override;

    virtual void onUpdate(milliseconds deltaTime) override;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<PauseHandler>(*this);
    }

    void togglePause();

    PauseHandler(const PauseHandler &other) : BehaviourScript(other) {
        previousMultiplier = other.previousMultiplier;
    };
    float previousMultiplier = 0.0;
};


#endif //BRACKOCALYPSE_PAUSEHANDLER_HPP
