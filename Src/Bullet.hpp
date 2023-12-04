//
// Created by jesse on 02/12/2023.
//

#ifndef BRACKOCALYPSE_BULLET_HPP
#define BRACKOCALYPSE_BULLET_HPP


#include <Objects/GameObject.hpp>

class Bullet : public GameObject {
public:
    Bullet(size_t layer);

    ~Bullet() = default;

    void setActive(bool active) const override;

};


#endif //BRACKOCALYPSE_BULLET_HPP
