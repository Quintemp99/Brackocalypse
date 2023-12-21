//
// Created by Olaf van den Berg on 20-12-2023.
//

#ifndef BRACKOCALYPSE_SECONDLEVEL_HPP
#define BRACKOCALYPSE_SECONDLEVEL_HPP


#include "../../../../Brack-Engine/outfacingInterfaces/Objects/Scene.hpp"
#include "../../../../Brack-Engine/outfacingInterfaces/BrackEngine.hpp"

class FirstLevel : public Scene {
public:
    FirstLevel() = default;

    void build() override;
};

#endif //BRACKOCALYPSE_SECONDLEVEL_HPP
