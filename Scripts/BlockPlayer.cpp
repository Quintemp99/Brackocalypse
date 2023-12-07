//
// Created by Olaf van den Berg on 28-11-2023.
//

#include <Components/CircleCollisionComponent.hpp>
#include <Components/BoxCollisionComponent.hpp>
#include "BlockPlayer.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/VelocityComponent.hpp"

void testMethod(TransformComponent &playerTransform, BoxCollisionComponent &playerCollision,
                TransformComponent &collidedWithTransform, BoxCollisionComponent &collidedWithCollision);

void BlockPlayer::onStart() {
}

void BlockPlayer::onUpdate(float deltaTime) {
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

    auto playerTopRight = Vector2(playerX + (playerSizeX * playerScaleX) / 2,
                                  playerY - (playerSizeY * playerScaleY) / 2);
    auto playerTopLeft = Vector2(playerX - (playerSizeX * playerScaleX) / 2,
                                 playerY - (playerSizeY * playerScaleY) / 2);
    auto playerBottomRight = Vector2(playerX + (playerSizeX * playerScaleX) / 2,
                                     playerY + (playerSizeY * playerScaleY) / 2);
    auto playerBottomLeft = Vector2(playerX - (playerSizeX * playerScaleX) / 2,
                                    playerY + (playerSizeY * playerScaleY) / 2);

    for (auto i: playerCollision.collidedWith) {
        auto collidedWithTransform = ComponentStore::GetInstance().tryGetComponent<TransformComponent>(i);
        auto collidedWithCollision = ComponentStore::GetInstance().tryGetComponent<BoxCollisionComponent>(i);

        auto collidedWithY = collidedWithTransform.position->getY();
        auto collidedWithX = collidedWithTransform.position->getX();
        auto collidedWithSizeX = collidedWithCollision.size->getX();
        auto collidedWithSizeY = collidedWithCollision.size->getY();
        auto collidedWithScaleX = collidedWithTransform.scale->getX();
        auto collidedWithScaleY = collidedWithTransform.scale->getY();


        auto collidedWithTopRight = Vector2(collidedWithX + (collidedWithSizeX * collidedWithScaleX) / 2,
                                            collidedWithY - (collidedWithSizeY * collidedWithScaleY) / 2);
        auto collidedWithTopLeft = Vector2(collidedWithX - (collidedWithSizeX * collidedWithScaleX) / 2,
                                           collidedWithY - (collidedWithSizeY * collidedWithScaleY) / 2);
        auto collidedWithBottomRight = Vector2(collidedWithX + (collidedWithSizeX * collidedWithScaleX) / 2,
                                               collidedWithY + (collidedWithSizeY * collidedWithScaleY) / 2);
        auto collidedWithBottomLeft = Vector2(collidedWithX - (collidedWithSizeX * collidedWithScaleX) / 2,
                                              collidedWithY + (collidedWithSizeY * collidedWithScaleY) / 2);



// Check collisions only on the Y-axis for top and bottom
        if (playerVelocity.velocity.getY() < 0) {  // Moving up
            if (std::abs((playerY - (playerSizeY * playerScaleY) / 2) -
                         (collidedWithY + (collidedWithSizeY * collidedWithScaleY) / 2)) < 1) {

                if (playerX + (playerSizeX * playerScaleX) / 2 >
                    collidedWithX - (collidedWithSizeX * collidedWithScaleX) / 2) {
                    continue;
                } else if (playerX - (playerSizeX * playerScaleX) / 2 <
                           collidedWithX + (collidedWithSizeX * collidedWithScaleX) / 2) {
                    continue;
                }

                playerVelocity.velocity.setY(0);
            }


        } else if (playerVelocity.velocity.getY() > 0) {  // Moving down

            if (std::abs((playerY + (playerSizeY * playerScaleY) / 2) -
                         (collidedWithY - (collidedWithSizeY * collidedWithScaleY) / 2)) < 1) {

                if (playerX + (playerSizeX * playerScaleX) / 2 >
                    collidedWithX - (collidedWithSizeX * collidedWithScaleX) / 2) {
                    continue;
                } else if (playerX - (playerSizeX * playerScaleX) / 2 <
                           collidedWithX + (collidedWithSizeX * collidedWithScaleX) / 2) {
                    continue;
                }

                playerVelocity.velocity.setY(0);
            }
        }

// Check collisions only on the X-axis for left and right
        if (playerVelocity.velocity.getX() < 0) {  // Moving left

            if (std::abs((playerX - (playerSizeX * playerScaleX) / 2) -
                         (collidedWithX + (collidedWithSizeX * collidedWithScaleX) / 2)) < 1) {

                if (playerY + (playerSizeY * playerScaleY) / 2 >
                    collidedWithY - (collidedWithSizeY * collidedWithScaleY) / 2) {
                    continue;
                } else if (playerY - (playerSizeY * playerScaleY) / 2 <
                           collidedWithY + (collidedWithSizeY * collidedWithScaleY) / 2) {
                    continue;
                }
                playerVelocity.velocity.setX(0);
            }
        } else if (playerVelocity.velocity.getX() > 0) {  // Moving right

            if (std::abs((playerX + (playerSizeX * playerScaleX) / 2) -
                         (collidedWithX - (collidedWithSizeX * collidedWithScaleX) / 2)) < 1) {
                if (playerY + (playerSizeY * playerScaleY) / 2 >
                    collidedWithY - (collidedWithSizeY * collidedWithScaleY) / 2) {
                    continue;
                } else if (playerY - (playerSizeY * playerScaleY) / 2 <
                           collidedWithY + (collidedWithSizeY * collidedWithScaleY) / 2) {
                    continue;
                }

                playerVelocity.velocity.setX(0);
            }
        }


    }


}

void testMethod(TransformComponent &playerTransform, BoxCollisionComponent &playerCollision,
                TransformComponent &collidedWithTransform, BoxCollisionComponent &collidedWithCollision) {
//    std::cout << "PlayerLinks"
//              << std::to_string(playerTransform.position->getX() - (playerCollision.size->getX() *
//                                                                    playerTransform.scale->getX()) / 2)
//              << std::endl;
//    std::cout << "WallRechts"
//              << std::to_string(
//                      collidedWithTransform.position->getX() +
//                      (collidedWithCollision.size->getX() * collidedWithTransform.scale->getX()) / 2)
//              << std::endl;
//    std::cout << "PlayerRechts"
//              << std::to_string(playerTransform.position->getX() + (playerCollision.size->getX() *
//                                                                    playerTransform.scale->getX()) / 2)
//              << std::endl;
//    std::cout << "WallLinks"
//              << std::to_string(
//                      collidedWithTransform.position->getX() -
//                      (collidedWithCollision.size->getX() * collidedWithTransform.scale->getX()) / 2)
//              << std::endl;
//    std::cout << "PlayerBoven"
//              << std::to_string(playerTransform.position->getY() -
//                                (playerCollision.size->getY() * collidedWithTransform.scale->getX()) / 2)
//              << std::endl;
//    std::cout << "WallOnder "
//              << std::to_string(
//                      collidedWithTransform.position->getY() +
//                      (collidedWithCollision.size->getY() * collidedWithTransform.scale->getY()) / 2)
//              << std::endl;
//    std::cout << "PlayerOnder"
//              << std::to_string(playerTransform.position->getY() +
//                                (playerCollision.size->getY() * collidedWithTransform.scale->getX()) / 2)
//              << std::endl;
//    std::cout << "WallBoven"
//              << std::to_string(
//                      collidedWithTransform.position->getY() -
//                      (collidedWithCollision.size->getY() * collidedWithTransform.scale->getY()) / 2)
//              << std::endl;
//    std::cout << "PositionPlayer:"
//              << std::to_string(playerTransform.position->getX())
//              << " "
//              << std::to_string(playerTransform.position->getY())
//              << std::endl;
//    std::cout << "PositionWall:"
//              << std::to_string(collidedWithTransform.position->getX())
//              << " "
//              << std::to_string(collidedWithTransform.position->getY())
//              << std::endl;
//    std::cout << "SizePlayer:"
//              << std::to_string(playerCollision.size->getX())
//              << " "
//              << std::to_string(playerCollision.size->getY())
//              << std::endl;
//    std::cout << "SizeWall:"
//              << std::to_string(collidedWithCollision.size->getX())
//              << " "
//              << std::to_string(collidedWithCollision.size->getY())
//              << std::endl;
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << std::endl;
}


