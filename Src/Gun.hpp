//
// Created by jesse on 30/11/2023.
//

#ifndef BRACKOCALYPSE_GUN_HPP
#define BRACKOCALYPSE_GUN_HPP


#include <cstdlib>
#include <Objects/GameObject.hpp>

class Gun : public GameObject {
public:
    Gun(size_t layer);

    ~Gun() = default;
};


#endif //BRACKOCALYPSE_GUN_HPP
