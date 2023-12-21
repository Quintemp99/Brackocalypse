//
// Created by Olaf van den Berg on 20-12-2023.
//

#ifndef BRACKOCALYPSE_SECONDLEVEL_HPP
#define BRACKOCALYPSE_SECONDLEVEL_HPP


#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"

class SecondLevel : public Scene {
public:
    SecondLevel() = default;

    void build() override;
};

#endif //BRACKOCALYPSE_SECONDLEVEL_HPP
