//
// Created by Olaf van den Berg on 28-11-2023.
//

#include <Components/CircleCollisionComponent.hpp>
#include <Components/BoxCollisionComponent.hpp>
#include "PlayerCollision.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/VelocityComponent.hpp"

void PlayerCollision::onStart() {
}

void PlayerCollision::onUpdate(float deltaTime) {
    auto player = getGameObjectByTag("Player");
    if (!player.has_value()) return;
    auto &playerCollision = player.value().tryGetComponent<BoxCollisionComponent>();
    auto &playerTransform = player.value().tryGetComponent<TransformComponent>();
    auto &playerVelocity = player.value().tryGetComponent<VelocityComponent>();

    auto playerY = playerTransform.position->getY();
    auto playerX = playerTransform.position->getX();
    auto playerSizeX = playerCollision.size->getX();
    auto playerSizeY = playerCollision.size->getY();
    auto playerScaleX = playerTransform.scale->getX();
    auto playerScaleY = playerTransform.scale->getY();

    for (auto i: playerCollision.collidedWith) {
        auto collidedWithTransform = ComponentStore::GetInstance().tryGetComponent<TransformComponent>(i);
        auto collidedWithCollision = ComponentStore::GetInstance().tryGetComponent<BoxCollisionComponent>(i);

        auto collidedWithY = collidedWithTransform.position->getY();
        auto collidedWithX = collidedWithTransform.position->getX();
        auto collidedWithSizeX = collidedWithCollision.size->getX();
        auto collidedWithSizeY = collidedWithCollision.size->getY();
        auto collidedWithScaleX = collidedWithTransform.scale->getX();
        auto collidedWithScaleY = collidedWithTransform.scale->getY();

// Check collisions only on the Y-axis for top and bottom
        if (playerVelocity.velocity.getY() < 0) {  // Moving up

            if ((playerY - (playerSizeY * playerScaleY) / 2) -
                (collidedWithY + (collidedWithSizeY * collidedWithScaleY) / 2) > -50) {


                if (std::abs((playerX - (playerSizeX * playerScaleX) / 2) -
                             (collidedWithX + (collidedWithSizeX * collidedWithScaleX) / 2)) < 5) {
                    continue;
                } else if (std::abs((playerX + (playerSizeX * playerScaleX) / 2) -
                                    (collidedWithX - (collidedWithSizeX * collidedWithScaleX) / 2)) < 5) {
                    continue;
                }

                playerTransform.position->setY((collidedWithY + (collidedWithSizeY * collidedWithScaleY) / 2) +
                                               (playerSizeY * playerScaleY) / 2);
                playerVelocity.velocity.setY(0);
            }


        } else if (playerVelocity.velocity.getY() > 0) {  // Moving down
            ;
            if ((playerY + (playerSizeY * playerScaleY) / 2) -
                (collidedWithY - (collidedWithSizeY * collidedWithScaleY) / 2) < 50) {

                if (std::abs((playerX - (playerSizeX * playerScaleX) / 2) -
                             (collidedWithX + (collidedWithSizeX * collidedWithScaleX) / 2)) < 5) {
                    continue;
                } else if (std::abs((playerX + (playerSizeX * playerScaleX) / 2) -
                                    (collidedWithX - (collidedWithSizeX * collidedWithScaleX) / 2)) < 5) {
                    continue;
                }

                playerTransform.position->setY((collidedWithY - (collidedWithSizeY * collidedWithScaleY) / 2) -
                                               (playerSizeY * playerScaleY) / 2);
                playerVelocity.velocity.setY(0);
            }
        }

// Check collisions only on the X-axis for left and right
        if (playerVelocity.velocity.getX() < 0) {  // Moving left

            if ((playerX - (playerSizeX * playerScaleX) / 2) -
                (collidedWithX + (collidedWithSizeX * collidedWithScaleX) / 2) > -50) {

                if (std::abs((playerY - (playerSizeY * playerScaleY) / 2) -
                             (collidedWithY + (collidedWithSizeY * collidedWithScaleY) / 2)) < 5) {
                    continue;
                } else if (std::abs((playerY + (playerSizeY * playerScaleY) / 2) -
                                    (collidedWithY - (collidedWithSizeY * collidedWithScaleY) / 2)) < 5) {
                    continue;
                }
                playerTransform.position->setX(((collidedWithX + (collidedWithSizeX * collidedWithScaleX) / 2) +
                                                (playerSizeX * playerScaleX) / 2));
                playerVelocity.velocity.setX(0);
            }
        } else if (playerVelocity.velocity.getX() > 0) {  // Moving right

            if ((playerX + (playerSizeX * playerScaleX) / 2) -
                (collidedWithX - (collidedWithSizeX * collidedWithScaleX) / 2) < 50) {
                
                if (std::abs((playerY - (playerSizeY * playerScaleY) / 2) -
                             (collidedWithY + (collidedWithSizeY * collidedWithScaleY) / 2)) < 10) {
                    continue;
                } else if (std::abs((playerY + (playerSizeY * playerScaleY) / 2) -
                                    (collidedWithY - (collidedWithSizeY * collidedWithScaleY) / 2)) < 10) {
                    continue;
                }
                playerTransform.position->setX(((collidedWithX - (collidedWithSizeX * collidedWithScaleX) / 2) -
                                                (playerSizeX * playerScaleX) / 2));
                playerVelocity.velocity.setX(0);
            }
        }
    }
}




