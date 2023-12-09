//
// Created by jesse on 30/11/2023.
//

#ifndef BRACKOCALYPSE_GUNFOLLOWMOUSE_HPP
#define BRACKOCALYPSE_GUNFOLLOWMOUSE_HPP


#include <BehaviourScripts/BehaviourScript.hpp>

class GunFollowMouse : public BehaviourScript {
public:
    GunFollowMouse() : BehaviourScript() {}

    ~GunFollowMouse() override = default;

    virtual void onStart() override;

    virtual void onUpdate(float deltaTime) override;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<GunFollowMouse>(*this);
    }

    GunFollowMouse(const GunFollowMouse &other) :
            BehaviourScript(other),
            distanceFromPlayer(other.distanceFromPlayer) {}

private:
    float distanceFromPlayer = 75;
};


#endif //BRACKOCALYPSE_GUNFOLLOWMOUSE_HPP
