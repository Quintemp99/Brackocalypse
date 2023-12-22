//
// Created by qtemp on 21-12-2023.
//

#ifndef WIFECOMPLAINTS_H
#define WIFECOMPLAINTS_H

#include <BehaviourScripts/BehaviourScript.hpp>

class WifeComplaints : public BehaviourScript{
public:
    explicit WifeComplaints() : BehaviourScript() {}
    ~WifeComplaints() override = default;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<WifeComplaints>(*this);
    }

    WifeComplaints(const WifeComplaints &other) : BehaviourScript(other) {
        soundInterval = other.soundInterval;
        soundPaths = other.soundPaths;
        lastSound = other.lastSound;
    }

    virtual void onStart() override;
    virtual void onUpdate(milliseconds deltaTime) override;
private:
    milliseconds soundInterval = 5000;
    milliseconds lastSound = 3000;
    std::vector<std::string> soundPaths = {
        "Sounds/wife-complaint1.mp3",
        "Sounds/wife-complaint2.mp3",
        "Sounds/wife-complaint3.mp3",
        "Sounds/wife-complaint4.mp3",
        "Sounds/wife-complaint5.mp3",
        "Sounds/wife-complaint6.mp3",
    };
};



#endif //WIFECOMPLAINTS_H
