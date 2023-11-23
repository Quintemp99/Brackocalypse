#include "SaveLoad.hpp"

const std::string SaveLoad::defaultPath{"./save_data.dat"};

bool SaveLoad::save() const {
    save(defaultPath);
}

bool SaveLoad::load() const {
    load(defaultPath);
}

bool SaveLoad::save(const std::string &filePath) const {
    std::string content;

    //Example data
    content += "level: 1\n";
    content += "player: Stijn\n";
    content += "xPosition: 1\n";
    content += "yPosition: 1\n";

    try {
        brackEngine.save(filePath, content);
        return true;
    } catch(std::exception exception) {
        Logger::Error("Unable to save file");
        return false;
    }
}

bool SaveLoad::load(const std::string &filePath) const {
    try {
        const auto& content = brackEngine.load(filePath);
        return true;
    } catch(std::exception exception) {
        Logger::Error("Unable to load file");
        return false;
    }
}
