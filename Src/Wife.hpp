//
// Created by qtemp on 21-12-2023.
//

#ifndef WIFE_HPP
#define WIFE_HPP
#include <Objects/GameObject.hpp>


class Wife : public GameObject {
public:
    Wife(size_t layer, int health);

    ~Wife() = default;
};



#endif //WIFE_HPP
