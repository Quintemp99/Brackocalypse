//
// Created by qtemp on 21-12-2023.
//

#ifndef BOSSLEVEL_HPP
#define BOSSLEVEL_HPP

#include "Objects/Scene.hpp"

class BossLevel : public Scene {
public:
    BossLevel() = default;

    void build() override;
};



#endif //BOSSLEVEL_HPP
