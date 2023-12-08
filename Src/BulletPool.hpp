//
// Created by jesse on 02/12/2023.
//

#ifndef BRACKOCALYPSE_BULLETPOOL_HPP
#define BRACKOCALYPSE_BULLETPOOL_HPP


#include <Objects/GameObject.hpp>
#include "Bullet.hpp"

class BulletPool : public GameObject {
public:
    BulletPool(size_t layer, size_t poolSize);

    ~BulletPool() = default;
};


#endif //BRACKOCALYPSE_BULLETPOOL_HPP
