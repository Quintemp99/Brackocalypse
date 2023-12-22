//
// Created by jesse on 21/12/2023.
//

#ifndef BRACKOCALYPSE_FULLSCREENHANDLER_HPP
#define BRACKOCALYPSE_FULLSCREENHANDLER_HPP


#include "BehaviourScripts/BehaviourScript.hpp"

class FullScreenHandler : public BehaviourScript{
    public:
    FullScreenHandler() : BehaviourScript() {}

    ~FullScreenHandler() override = default;

    virtual void onStart() override;

    virtual void onUpdate(milliseconds deltaTime) override;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<FullScreenHandler>(*this);
    }

    FullScreenHandler(const FullScreenHandler &other) : BehaviourScript(other) {};
};


#endif //BRACKOCALYPSE_FULLSCREENHANDLER_HPP
