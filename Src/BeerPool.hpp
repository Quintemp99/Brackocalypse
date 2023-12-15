//
// Created by jesse on 02/12/2023.
//

#ifndef BRACKOCALYPSE_BEERPOOL_HPP
#define BRACKOCALYPSE_BEERPOOL_HPP


#include <Objects/GameObject.hpp>
#include "Bullet.hpp"

class BeerPool : public GameObject {
public:
    BeerPool(size_t poolSize);
    ~BeerPool() = default;
};


#endif //BRACKOCALYPSE_BULLETPOOL_HPP
