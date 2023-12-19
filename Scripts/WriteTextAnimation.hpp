//
// Created by SKIKK on 19/12/2023.
//

#ifndef BRACKOCALYPSE_WRITETEXTANIMATION_HPP
#define BRACKOCALYPSE_WRITETEXTANIMATION_HPP


#include <BehaviourScripts/BehaviourScript.hpp>

class WriteTextAnimation : public BehaviourScript{
public:
    explicit WriteTextAnimation(std::vector<std::string> lines) : BehaviourScript(), lines_(lines) {}
    ~WriteTextAnimation() override = default;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<WriteTextAnimation>(*this);
    }

    WriteTextAnimation(const WriteTextAnimation &other) : BehaviourScript(other) {
        lines_ = other.lines_;
        writeInterval = other.writeInterval;
        lastWrite = other.lastWrite;
        linePos = other.linePos;
        charPos = other.charPos;
        soundInterval = other.soundInterval;
        lastSound = other.lastSound;
    }

    virtual void onStart() override;
    virtual void onUpdate(milliseconds deltaTime) override;
private:
    std::vector<std::string> lines_;
    milliseconds writeInterval = 20;
    milliseconds lastWrite = 0;
    milliseconds soundInterval = 40;
    milliseconds lastSound = 0;
    std::vector<std::string> soundPaths = {"Sounds/type-sound1.mp3", "Sounds/type-sound2.mp3", "Sounds/type-sound3.mp3", "Sounds/type-sound4.mp3"};
    int linePos = 0;
    int charPos = 0;
};


#endif //BRACKOCALYPSE_WRITETEXTANIMATION_HPP
