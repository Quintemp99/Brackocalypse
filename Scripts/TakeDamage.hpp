//
// Created by jesse on 15/12/2023.
//

#ifndef BRACKOCALYPSE_TAKEDAMAGE_HPP
#define BRACKOCALYPSE_TAKEDAMAGE_HPP


#include <BehaviourScripts/BehaviourScript.hpp>

class TakeDamage : public BehaviourScript {
public:
    TakeDamage() : BehaviourScript() {}

    ~TakeDamage() override = default;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<TakeDamage>(*this);
    }

    virtual void onStart() override;

    virtual void onUpdate(milliseconds deltaTime) override;

    void doDamage(int damage);
};


#endif //BRACKOCALYPSE_TAKEDAMAGE_HPP
