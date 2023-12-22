//
// Created by stijn on 21-12-2023.
//

#ifndef BRACKOCALYPSE_CREDITSSCROLL_HPP
#define BRACKOCALYPSE_CREDITSSCROLL_HPP

#include "BehaviourScripts/BehaviourScript.hpp"

class CreditsScroll : public BehaviourScript {
public:
    CreditsScroll() : BehaviourScript() {}
    ~CreditsScroll() override = default;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<CreditsScroll>(*this);
    }

    CreditsScroll(const CreditsScroll &other) : BehaviourScript(other) {};

    virtual void onStart() override;
    virtual void onUpdate(milliseconds deltaTime) override;
private:
    int currentNewestIndex = 0;
    float speed = 0.1;
    static const int extraSpace = 50;

    int getCreditHeight(GameObject& gameObject);
};


#endif //BRACKOCALYPSE_CREDITSSCROLL_HPP
