//
// Created by Olaf van den Berg on 28-11-2023.
//

#ifndef BRACKOCALYPSE_PLAYERCOLLISION_HPP
#define BRACKOCALYPSE_PLAYERCOLLISION_HPP


#include <BehaviourScripts/BehaviourScript.hpp>

class PlayerCollision : public BehaviourScript {
public:
    PlayerCollision() : BehaviourScript() {}

    ~PlayerCollision() override = default;

    void onStart() override;

    void onUpdate(float deltaTime) override;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<PlayerCollision>(*this);
    }

    PlayerCollision(const PlayerCollision &other) : BehaviourScript(other) {}


};


#endif //BRACKOCALYPSE_PLAYERCOLLISION_HPP
