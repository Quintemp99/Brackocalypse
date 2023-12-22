//
// Created by SKIKK on 23/11/2023.
//

#ifndef BRACKOCALYPSE_FOLLOWGAMEOBJECT_HPP
#define BRACKOCALYPSE_FOLLOWGAMEOBJECT_HPP

#include <BehaviourScripts/BehaviourScript.hpp>

class FollowGameObject : public BehaviourScript {
public:
public:
    FollowGameObject(std::string tag) : BehaviourScript(), followGameObjectTag(tag) {}

    ~FollowGameObject() override = default;

    virtual void onStart() override;

    virtual void onUpdate(float deltaTime) override;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<FollowGameObject>(*this);
    }

    FollowGameObject(const FollowGameObject &other) :
            BehaviourScript(other),
            moveCameraMargin(other.moveCameraMargin),
            followGameObjectTag(other.followGameObjectTag) {}

private:
    float moveCameraMargin = 30;
    std::string followGameObjectTag;
};


#endif //BRACKOCALYPSE_FOLLOWGAMEOBJECT_HPP
