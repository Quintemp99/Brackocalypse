//
// Created by Olaf van den Berg on 11-12-2023.
//

#ifndef BRACKOCALYPSE_ENEMY_HPP
#define BRACKOCALYPSE_ENEMY_HPP


#include <Objects/GameObject.hpp>
#include <Helpers/Vector2.hpp>

class Enemy : public GameObject {
public:
    Enemy(size_t layer);

    ~Enemy() = default;

    int health_ = 3;
};


#endif //BRACKOCALYPSE_ENEMY_HPP
