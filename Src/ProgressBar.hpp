#ifndef BRACKOCALYPSE_PROGRESSBAR_HPP
#define BRACKOCALYPSE_PROGRESSBAR_HPP

#include <Objects/GameObject.hpp>
#include "Helpers/Vector2.hpp"

class ProgressBar : public GameObject {
public:
    ProgressBar(Vector2 size);
    ~ProgressBar() = default;
};


#endif //BRACKOCALYPSE_PROGRESSBAR_HPP
