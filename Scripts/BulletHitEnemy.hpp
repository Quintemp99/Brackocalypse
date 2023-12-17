//
// Created by jesse on 15/12/2023.
//

#ifndef BRACKOCALYPSE_BULLETHITENEMY_HPP
#define BRACKOCALYPSE_BULLETHITENEMY_HPP


#include <BehaviourScripts/BehaviourScript.hpp>


class BulletHitEnemy : public BehaviourScript {
public:
    BulletHitEnemy() : BehaviourScript() {}

    ~BulletHitEnemy() override = default;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<BulletHitEnemy>(*this);
    }

    virtual void onStart() override;

    virtual void onUpdate(milliseconds deltaTime) override;
};


#endif //BRACKOCALYPSE_BULLETHITENEMY_HPP
