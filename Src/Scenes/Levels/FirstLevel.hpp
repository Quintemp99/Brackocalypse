#ifndef BRACKOCALYPSE_DEMOLEVEL_HPP
#define BRACKOCALYPSE_DEMOLEVEL_HPP

#include "Objects/Scene.hpp"
#include "BrackEngine.hpp"

class FirstLevel : public Scene {
public:
    FirstLevel() = default;

    void build() override;
};


#endif //BRACKOCALYPSE_DEMOLEVEL_HPP
