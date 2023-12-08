//
// Created by stijn on 6-12-2023.
//

#ifndef BRACKOCALYPSE_BEER_HPP
#define BRACKOCALYPSE_BEER_HPP

#include <Objects/GameObject.hpp>

class Beer : public GameObject {
public:
    Beer() : GameObject() {
        setTag("Beer");
    }
};


#endif //BRACKOCALYPSE_BEER_HPP
