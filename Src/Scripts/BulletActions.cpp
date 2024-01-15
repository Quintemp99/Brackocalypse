//
// Created by jesse on 04/12/2023.
//

#include <Components/BoxCollisionComponent.hpp>
#include <Components/RigidBodyComponent.hpp>
#include <Components/VelocityComponent.hpp>
#include "BulletActions.hpp"
#include "TakeDamage.hpp"

void BulletActions::onStart() {
}

void BulletActions::onUpdate(milliseconds deltaTime) {
    timer += deltaTime;
    if (timer >= lifeTime) {
        setInactive();
    }

    if (!canHitWife) {
        wifeTimer += deltaTime;
        if (wifeTimer >= wifeTime) {
            canHitWife = true;
            wifeTimer = 0.0f;
        }
    }

    if (auto &collision = tryGetComponent<BoxCollisionComponent>(); !collision.collidedWith.empty()) {
        for (const auto &entity: collision.collidedWith) {
            const auto &boxCollision = ComponentStore::GetInstance().tryGetComponent<BoxCollisionComponent>(entity);
            auto &objectInfo = ComponentStore::GetInstance().tryGetComponent<ObjectInfoComponent>(entity);
            if (objectInfo.tag == "EnemyCollision") {
                const auto &parent = ComponentStore::GetInstance().tryGetComponent<ParentComponent>(entity);
                auto &enemyRigidBody = ComponentStore::GetInstance().tryGetComponent<RigidBodyComponent>(
                        parent.parentId);
                enemyRigidBody.force = std::make_unique<Vector2>(
                        tryGetComponent<VelocityComponent>().velocity * 2500.0f);
                auto &takeDamage = BehaviourScriptStore::getInstance().tryGetBehaviourScript<TakeDamage>(
                        parent.parentId);
                takeDamage.doDamage(1);
                break;
            } else if (objectInfo.tag == "WifeCollision") {
                if (!canHitWife) continue;
                canHitWife = false;
                const auto &parent = ComponentStore::GetInstance().tryGetComponent<ParentComponent>(entity);
                auto &enemyRigidBody = ComponentStore::GetInstance().tryGetComponent<RigidBodyComponent>(
                        parent.parentId);
                enemyRigidBody.force = std::make_unique<Vector2>(
                        tryGetComponent<VelocityComponent>().velocity * 2500.0f);
                auto &takeDamage = BehaviourScriptStore::getInstance().tryGetBehaviourScript<TakeDamage>(
                        parent.parentId);
                takeDamage.doDamage(1);
                break;
            } else {
                if (boxCollision.isTrigger) continue;
                auto &rigidBody = ComponentStore::GetInstance().tryGetComponent<RigidBodyComponent>(entity);
                auto velocity = tryGetComponent<VelocityComponent>().velocity * 2500.0f;
                rigidBody.force = std::make_unique<Vector2>(velocity);
                break;
            }
        }
        setInactive();
        collision.collidedWith.clear();
    }
}

void BulletActions::setInactive() {
    timer = 0.0f;
    setActive(false);
}
