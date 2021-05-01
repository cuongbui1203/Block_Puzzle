#include "sound.h"
#include "common.h"
#include "init.h"
void vocaloid::create(){
    music           = nullptr;
    effect          = nullptr;
    singingEffect   = false;
    singingMusic    = false;

    music = Mix_LoadMUS(PATH_BGM.c_str());
    effect = Mix_LoadWAV(PATH_EFFECT_WAV.c_str());
    if(music == nullptr){
        logSDLError(std::cout,"load bgm",true);
    }
    if(effect == nullptr){
        logSDLError(std::cout,"load effect",true);
    }

}


void vocaloid::sing(void){
    if(music != nullptr){
        if(singingMusic == true && Mix_PlayingMusic())
            Mix_ResumeMusic();
        else
            Mix_PauseMusic();
    }
}
void vocaloid::playEffect(void){
    if(effect != nullptr && singingEffect == true){
        Mix_PlayChannel(1,effect,0);
    }
}

void vocaloid::free(void){
    Mix_FreeChunk(effect);
    Mix_FreeMusic(music);

    music           = nullptr;
    effect          = nullptr;
}

void vocaloid::begin(void){
    Mix_PlayMusic(music,-1);
}
