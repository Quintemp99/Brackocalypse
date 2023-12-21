//
// Created by jesse on 19/12/2023.
//

#include <Components/SoundEffectComponent.hpp>
#include <Components/BoxCollisionComponent.hpp>
#include <Components/RigidBodyComponent.hpp>
#include "PlayBoxMovingSound.hpp"

#include "Components/CircleCollisionComponent.hpp"

void PlayBoxMovingSound::onStart() {
}

void PlayBoxMovingSound::onUpdate(milliseconds deltaTime) {
    timer -= deltaTime;
    if (timer <= 0) {
        canPlay = true;
    }

    if (canPlay) {
        auto &collisionComponent = getCollisionComponent();
        if (collisionComponent.collidedWith.empty()) {
            timer = 0;
            return;
        } else {
            for (auto collidedWith: collisionComponent.collidedWith) {
                auto &collision = getCollisionComponent(collidedWith);
                if (collision.isTrigger) continue;
                auto &rigidBody = ComponentStore::GetInstance().tryGetComponent<RigidBodyComponent>(collidedWith);
                if (rigidBody.collisionType == CollisionType::STATIC) continue;
                auto &audio = tryGetComponent<SoundEffectComponent>();
                audio.startPlaying = true;
                timer = interval;
                canPlay = false;
                return;
            }
        }
    }
}

CollisionArchetype& PlayBoxMovingSound::getCollisionComponent()
{
    return getCollisionComponent(entityId);
}

CollisionArchetype& PlayBoxMovingSound::getCollisionComponent(entity id)
{
    try
    {
        return ComponentStore::GetInstance().tryGetComponent<BoxCollisionComponent>(id);
    }
    catch (...)
    {
        return ComponentStore::GetInstance().tryGetComponent<CircleCollisionComponent>(id);
    }
}


