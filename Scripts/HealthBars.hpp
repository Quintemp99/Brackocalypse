//
// Created by Olaf van den Berg on 18/12/2023.
//

#ifndef BRACKOCALYPSE_HEALTHBARS_HPP
#define BRACKOCALYPSE_HEALTHBARS_HPP


#include "BehaviourScripts/BehaviourScript.hpp"

class HealthBars : public BehaviourScript {
public:
    HealthBars() : BehaviourScript() {}

    ~HealthBars() override = default;

    virtual void onStart() override;

    virtual void onUpdate(milliseconds deltaTime) override;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<HealthBars>(*this);
    }
};


#endif //BRACKOCALYPSE_HEALTHBARS_HPP
