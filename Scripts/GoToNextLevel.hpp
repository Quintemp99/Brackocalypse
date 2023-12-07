//
// Created by stijn on 6-12-2023.
//

#ifndef BRACKOCALYPSE_GOTONEXTLEVEL_HPP
#define BRACKOCALYPSE_GOTONEXTLEVEL_HPP

#include <Components/BehaviourScript.hpp>

class GoToNextLevel : public BehaviourScript {
public:
    GoToNextLevel() = default;

    virtual void onStart() override;
    virtual void onUpdate(float deltaTime) override;
    bool maxForLevel = 10;
};


#endif //BRACKOCALYPSE_GOTONEXTLEVEL_HPP
