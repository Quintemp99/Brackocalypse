//
// Created by jesse on 18/12/2023.
//

#ifndef BRACKOCALYPSE_CRATE_HPP
#define BRACKOCALYPSE_CRATE_HPP


#include <Objects/GameObject.hpp>
#include <Helpers/Vector2.hpp>

class Crate : public GameObject {
public:
    Crate(size_t layer, Vector2 position);

    ~Crate() = default;
};


#endif //BRACKOCALYPSE_CRATE_HPP
