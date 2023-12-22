#ifndef BRACKOCALYPSE_DEMOLEVEL_HPP
#define BRACKOCALYPSE_DEMOLEVEL_HPP

#include "Objects/Scene.hpp"

class SecondLevel : public Scene {
public:
    SecondLevel() = default;

    void build() override;
};


#endif //BRACKOCALYPSE_DEMOLEVEL_HPP
