//
// Created by Olaf van den Berg on 18/12/2023.
//

#ifndef BRACKOCALYPSE_UPDATEHEALTH_HPP
#define BRACKOCALYPSE_UPDATEHEALTH_HPP


#include "BehaviourScripts/BehaviourScript.hpp"

class UpdateHealth : public BehaviourScript {
public:
    UpdateHealth() : BehaviourScript() {}

    ~UpdateHealth() override = default;

    virtual void onStart() override;

    virtual void onUpdate(milliseconds deltaTime) override;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<UpdateHealth>(*this);
    }
};


#endif //BRACKOCALYPSE_UPDATEHEALTH_HPP
