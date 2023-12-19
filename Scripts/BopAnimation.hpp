//
// Created by SKIKK on 19/12/2023.
//

#ifndef BRACKOCALYPSE_BOPANIMATION_HPP
#define BRACKOCALYPSE_BOPANIMATION_HPP


#include <BehaviourScripts/BehaviourScript.hpp>


class BopAnimation : public BehaviourScript {
public:
    BopAnimation(int bopDepth, milliseconds fullLoopTime) : BehaviourScript(), bopDepth_(bopDepth) {
        changeInterval_ = fullLoopTime / bopDepth;
    }

    ~BopAnimation() override = default;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<BopAnimation>(*this);
    }

    virtual void onStart() override;

    virtual void onUpdate(milliseconds deltaTime) override;

    BopAnimation(const BopAnimation &other) : BehaviourScript(other) {
        bopDepth_ = other.bopDepth_;
        bopProgress_ = other.bopProgress_;
        up_ = other.up_;
        changeInterval_ = other.changeInterval_;
        lastChange_ = other.lastChange_;
    }
private:
    int bopDepth_;
    int bopProgress_ = 0;
    bool up_ = false;
    milliseconds changeInterval_;
    milliseconds lastChange_ = 0;
};

#endif //BRACKOCALYPSE_BOPANIMATION_HPP
