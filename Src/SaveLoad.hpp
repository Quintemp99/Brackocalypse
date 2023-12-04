#ifndef BRACKOCALYPSE_SAVELOAD_HPP
#define BRACKOCALYPSE_SAVELOAD_HPP

#include "BrackEngine.hpp"

class SaveLoad {
public:
    SaveLoad(const BrackEngine& brackEngine) : brackEngine(brackEngine) {}
    ~SaveLoad() {};

    bool save() const;
    bool load() const;
    bool save(const std::string& filePath) const;
    bool load(const std::string& filePath) const;
private:
    const BrackEngine& brackEngine;
    static const std::string defaultPath;
};


#endif //BRACKOCALYPSE_SAVELOAD_HPP
