//
// Created by SKIKK on 24/11/2023.
//

#ifndef BRACKOCALYPSE_MUTEBUTTON_HPP
#define BRACKOCALYPSE_MUTEBUTTON_HPP
#include <Objects/Button.hpp>
class MuteButton : public Button{
public:
    MuteButton() : Button(Vector2(50,50), "Mute") {
        setFontSize(24);
        setClickEvent([](){
            auto soundTrackIds = ComponentStore::GetInstance().getEntitiesWithComponent<SoundTrackComponent>();
            for (uint32_t soundTrackId: soundTrackIds) {
                auto& soundTrackComponent = ComponentStore::GetInstance().tryGetComponent<SoundTrackComponent>(soundTrackId);
                if(soundTrackComponent.pauseSound){
                    soundTrackComponent.startPlaying = true;
                }else{
                    soundTrackComponent.pauseSound = true;
                }
            }
        });
    }
};
#endif //BRACKOCALYPSE_MUTEBUTTON_HPP