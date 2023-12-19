//
// Created by SKIKK on 19/12/2023.
//

#include <Components/TransformComponent.hpp>
#include "BopAnimation.hpp"

void BopAnimation::onStart() {

}

void BopAnimation::onUpdate(milliseconds deltaTime) {
    if(lastChange_ <= 0){
        auto& transformComponent = tryGetComponent<TransformComponent>();
        if(up_){
            bopProgress_--;
            transformComponent.position->setY(transformComponent.position->getY() - 1);
        }else{
            bopProgress_++;
            transformComponent.position->setY(transformComponent.position->getY() + 1);
        }

        if(bopProgress_ >= bopDepth_){
            up_ = true;
        }else if (bopProgress_ <= 0){
            up_ = false;
        }
        lastChange_ = changeInterval_;
    } else{
        lastChange_ -= deltaTime;
    }
}