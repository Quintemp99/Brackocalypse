//
// Created by Olaf van den Berg on 13-12-2023.
//

#ifndef BRACKOCALYPSE_ENEMYPOOL_HPP
#define BRACKOCALYPSE_ENEMYPOOL_HPP


#include <Objects/GameObject.hpp>

class EnemyPool : public GameObject {

public:
    EnemyPool(size_t layer, size_t poolSize);

    ~EnemyPool() = default;
};


#endif //BRACKOCALYPSE_ENEMYPOOL_HPP
