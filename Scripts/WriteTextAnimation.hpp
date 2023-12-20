//
// Created by SKIKK on 19/12/2023.
//

#ifndef BRACKOCALYPSE_WRITETEXTANIMATION_HPP
#define BRACKOCALYPSE_WRITETEXTANIMATION_HPP


#include <BehaviourScripts/BehaviourScript.hpp>
#include <Objects/Scene.hpp>

class WriteTextAnimation : public BehaviourScript{
public:
    explicit WriteTextAnimation(std::vector<std::string> lines, Scene* nextScene) : BehaviourScript(), lines(lines), nextScene(nextScene) {}
    ~WriteTextAnimation() override;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<WriteTextAnimation>(*this);
    }

    WriteTextAnimation(const WriteTextAnimation &other) : BehaviourScript(other) {
        lines = other.lines;
        writeInterval = other.writeInterval;
        lastWrite = other.lastWrite;
        linePos = other.linePos;
        charPos = other.charPos;
        soundInterval = other.soundInterval;
        soundPaths = other.soundPaths;
        lastSound = other.lastSound;
        nextScene = other.nextScene;
    }

    virtual void onStart() override;
    virtual void onUpdate(milliseconds deltaTime) override;
private:
    Scene* nextScene;
    std::vector<std::string> lines;
    milliseconds writeInterval = 20;
    milliseconds lastWrite = 0;
    milliseconds soundInterval = 40;
    milliseconds lastSound = 0;
    std::vector<std::string> soundPaths = {"Sounds/type-sound1.mp3", "Sounds/type-sound2.mp3", "Sounds/type-sound3.mp3", "Sounds/type-sound4.mp3"};
    int linePos = 0;
    int charPos = 0;
};


#endif //BRACKOCALYPSE_WRITETEXTANIMATION_HPP
