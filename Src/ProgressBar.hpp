#ifndef BRACKOCALYPSE_PROGRESSBAR_HPP
#define BRACKOCALYPSE_PROGRESSBAR_HPP

#include <Objects/GameObject.hpp>

class ProgressBar : public GameObject {
public:
    ProgressBar();
    ~ProgressBar() = default;
private:
    const int totalWidth = 300;
};


#endif //BRACKOCALYPSE_PROGRESSBAR_HPP
