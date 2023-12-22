//
// Created by qtemp on 21-12-2023.
//

#ifndef WIFEDEATH_HPP
#define WIFEDEATH_HPP

#include <BehaviourScripts/BehaviourScript.hpp>

class WifeDeath : public BehaviourScript{
    public:
    explicit WifeDeath() : BehaviourScript() {}
    ~WifeDeath() override = default;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<WifeDeath>(*this);
    }

    WifeDeath(const WifeDeath &other) : BehaviourScript(other) {}

    virtual void onStart() override;
    virtual void onUpdate(milliseconds deltaTime) override;
};



#endif //WIFEDEATH_HPP
