//
// Created by jesse on 30/11/2023.
//

#ifndef BRACKOCALYPSE_GUNSHOOTING_HPP
#define BRACKOCALYPSE_GUNSHOOTING_HPP


#include <BehaviourScripts/BehaviourScript.hpp>

class GunShooting : public BehaviourScript {
public:
    GunShooting() : BehaviourScript() {}

    ~GunShooting() override = default;

    virtual void onStart() override;

    virtual void onUpdate(milliseconds deltaTime) override;

    std::unique_ptr<IBehaviourScript> clone() const override {
        return std::make_unique<GunShooting>(*this);
    }

    GunShooting(const GunShooting &other) :
            BehaviourScript(other) {};
private:
    float cameraShakeIntensity = 2.5f;
    milliseconds cameraShakeDuration = 100.0f;
    milliseconds cameraShakeTimer = 0.0f;
    bool shaking = false;
    Vector2 originalCameraPosition;
    std::mt19937 randomGenerator{std::random_device{}()};
    std::uniform_real_distribution<float> distribution{-1.0f, 1.0f};

    void shakeCamera();

    void shoot();

};


#endif //BRACKOCALYPSE_GUNSHOOTING_HPP
